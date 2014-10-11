#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char *args[])
{
  CURL *curl;
  CURLcode res;

  printf("[+] Tested Stuff For: %s\n", args[1]);

  curl = curl_easy_init();
  if(curl) {
    char url[100];
    snprintf(url, 99, "http://api.twitch.tv/api/channels/%s/access_token", args[1]);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  return 0;
}
