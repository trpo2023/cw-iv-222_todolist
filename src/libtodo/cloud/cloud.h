#include <string>
using namespace std;

#define GET_INFO_LOGPAS(log, pas) "/getinfo?login=" + log + "&pass=" + pas
#define SET_INFO_LOGPAS(log, pas) "/setinfo?login=" + log + "&pass=" + pas

string GetUrlResponse(string request, string post_string);
string GetUrlResponse(string request);
void DownloadSaves(string login, string password);
void UploadSaves(string login, string password);