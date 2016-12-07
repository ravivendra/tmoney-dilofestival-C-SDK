#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

using namespace std;

int main() {
	CURL *curl;
  	CURLcode response;
 
  	curl_global_init(CURL_GLOBAL_ALL);
  	
  	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
	headers = curl_slist_append(headers, "Authorization: Bearer _SET_IT_WITH_YOUR_OWN_KEY_");
 
  	curl = curl_easy_init();
  	
  	if(curl) {
	    curl_easy_setopt(curl, CURLOPT_URL, "https://api.mainapi.net/tmoney/1.0.0/sign-in");
	    curl_easy_setopt(curl, CURLOPT_HEADER, headers);
	    curl_easy_setopt(curl, CURLOPT_POST, 1);
	    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "userName=YOUR_OWN_EMAIL&password=YOU_OWN_PASSWORD&terminal=ASKED_TO_INSTRUCTOR");
 
    	response = curl_easy_perform(curl);
    
    	if(response != CURLE_OK)
      		fprintf(stderr, "cURL was failed : %s\n",
        		curl_easy_strerror(response));
 
    	curl_easy_cleanup(curl);
  	}
  
  	curl_global_cleanup();
  	
  	return EXIT_SUCCESS;
}
