#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

using namespace std;

int main() {
	CURL *curl;
  	CURLcode response;

  	curl_global_init(CURL_GLOBAL_ALL);


  	const char* BASE_API_KEY = "_SET_IT_WITH_YOUR_OWN_KEY_";
  	const char* USERNAME = "_YOUR_OWN_TMONEY_ACCOUNT_";
  	const char* PASSWORD = "_YOUR_OWN_TMONEY_PASSWORD_";
  	const char* TERMINAL = "_ASKED_TO_INSTRUCTOR_";


  	if(BASE_API_KEY == "" || BASE_API_KEY == "_SET_IT_WITH_YOUR_OWN_KEY_") {
  		printf("%s", "Set your own key from our system (www.mainapi.net)");
  		return EXIT_SUCCESS;
	} else if(USERNAME == "" || USERNAME == "_YOUR_OWN_TMONEY_ACCOUNT_") {
  		printf("%s", "Set your own T-MONEY account");
  		return EXIT_SUCCESS;
	} else if(PASSWORD == "" || PASSWORD == "_YOUR_OWN_TMONEY_PASSWORD_") {
  		printf("%s", "Set your own T-MONEY password");
  		return EXIT_SUCCESS;
	} else if(TERMINAL == "" || TERMINAL == "_ASKED_TO_INSTRUCTOR_") {
  		printf("%s", "Asked for the Terminal to the instructor");
  		return EXIT_SUCCESS;
	}


 	char authorization = printf("Authorization: Bearer %s", BASE_API_KEY);
 	char body = printf("userName=%s&password=%s&terminal=%s", USERNAME, PASSWORD, TERMINAL);


	struct curl_slist *headers = NULL;

	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
	headers = curl_slist_append(headers, (const char*) authorization);


  	curl = curl_easy_init();


  	if(curl) {
	    curl_easy_setopt(curl, CURLOPT_URL, "https://api.mainapi.net/tmoney/1.0.0/sign-in");
	    curl_easy_setopt(curl, CURLOPT_HEADER, headers);
	    curl_easy_setopt(curl, CURLOPT_POST, 1);
	    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, (const char*) body);

    	response = curl_easy_perform(curl);

    	if(response != CURLE_OK)
      		fprintf(stderr, "cURL was failed : %s\n",
        		curl_easy_strerror(response));

    	curl_easy_cleanup(curl);
  	}

  	curl_global_cleanup();

  	return EXIT_SUCCESS;
}
