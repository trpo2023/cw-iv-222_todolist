#include <libtodo/cloud/cloud.h>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast.hpp>

#include <fstream>
using namespace std;

#define IP_ADDR_REST_API_SERVER "109.174.17.2"
#define BASE_PORT "18080"

namespace http = boost::beast::http;

string GetUrlResponse(string request, string post_string)
{
    boost::asio::io_context io;
    boost::asio::ip::tcp::resolver resolver(io);
    boost::asio::ip::tcp::socket socket(io);

    boost::asio::connect(
            socket, resolver.resolve(IP_ADDR_REST_API_SERVER, BASE_PORT));

    http::request<http::string_body> req;

    if (post_string == "") {
        req = http::request<http::string_body>(http::verb::get, request, 3);
    } else {
        req = http::request<http::string_body>(http::verb::post, request, 3);
    }

    req.set(http::field::host, IP_ADDR_REST_API_SERVER);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    if (post_string != "") {
        req.set(http::field::content_type, "text/plain");
        req.body() = post_string;
        req.prepare_payload();
    }

    http::write(socket, req);

    string response;
    {
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);
        response = boost::beast::buffers_to_string(res.body().data());
    }
    socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    return response;
}

string GetUrlResponse(string request)
{
    return GetUrlResponse(request, "");
}

void DownloadSaves(string login, string password)
{
    string fileText = GetUrlResponse(GET_INFO_LOGPAS(login, password));
    if (fileText != "ERROR") {
        ofstream f(".saves.save");
        f << fileText;
    }
}
void UploadSaves(string login, string password)
{
    ifstream f(".saves.save");
    stringstream ss;
    ss << f.rdbuf();
    string res = ss.str();
    string s = GetUrlResponse(SET_INFO_LOGPAS(login, password), res);
}