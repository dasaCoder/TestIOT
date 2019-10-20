#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

void thermometer(double temp) {
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "api.thingspeak.com:80");
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "field1=" + std::to_string(temp) + "&key=example");
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		cout << endl;
	}
	//return 0;
}

int main() {

	thermometer(42.3);
}