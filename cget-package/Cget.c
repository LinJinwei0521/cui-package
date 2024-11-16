#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Write callback function to save the downloaded content
size_t write_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int download_file(const char *url, const char *output_filename) {
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Open output file
        fp = fopen(output_filename, "wb");
        if (!fp) {
            fprintf(stderr, "Unable to open file %s\n", output_filename);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return -1;
        }

        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set callback function to handle the downloaded data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform download
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return -1;
        }

        printf("File has been downloaded to %s\n", output_filename);

        // Clean up resources
        fclose(fp);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Unable to initialize libcurl\n");
        curl_global_cleanup();
        return -1;
    }

    curl_global_cleanup();
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <output file>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    const char *output_filename = argv[2];

    return download_file(url, output_filename);
}
