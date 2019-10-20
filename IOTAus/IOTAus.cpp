#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>
#include <string>

using namespace std;

void thermometer(double temp) {
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	string api_key = "your api key";

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://iottest.free.beeceptor.com");
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "field1=" + std::to_string(temp) + "&key=" + api_key);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
			cout << curl_easy_strerror(res) << endl;

		cout << res << endl;
		curl_easy_cleanup(curl);
	}
	else {
		cout << "not run";
	}
	//return 0;
}

int main() {

	thermometer(42.3);
}