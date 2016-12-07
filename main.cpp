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
	headers = curl_slist_append(headers, "Authorization: Bearer 3e60e5d18c9a83b4c4d89961aaf8f25c");
 
  	curl = curl_easy_init();
  	
  	if(curl) {
	    curl_easy_setopt(curl, CURLOPT_URL, "https://api.mainapi.net/tmoney/1.0.0/sign-in");
	    curl_easy_setopt(curl, CURLOPT_HEADER, headers);
	    curl_easy_setopt(curl, CURLOPT_POST, 1);
	    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "userName=tmoney.testing1@gmail.com&password=T3lkom2016&terminal=WEB-TMONEY");
 
    	response = curl_easy_perform(curl);
    
    	if(response != CURLE_OK)
      		fprintf(stderr, "cURL was failed : %s\n",
        		curl_easy_strerror(response));
 
    	curl_easy_cleanup(curl);
  	}
  
  	curl_global_cleanup();
  	
  	return EXIT_SUCCESS;
}
