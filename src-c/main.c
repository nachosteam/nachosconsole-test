/*
   Copyright 2025 NachosTeam

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toml.h"
#include <openssl/sha.h>

int main(void) {
    const char* input = "Hello, world!";
    unsigned char hash[SHA512_DIGEST_LENGTH];

    SHA512((unsigned char*)input, strlen(input), hash);

    printf("SHA512: ");
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");

    //////////////////////////////////////

    FILE* fp = fopen("test.toml", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char errbuf[200];
    toml_table_t* conf = toml_parse_file(fp, errbuf, sizeof(errbuf));
    fclose(fp);

    if (!conf) {
        fprintf(stderr, "TOML parse error: %s\n", errbuf);
        return 1;
    }

    toml_table_t* db = toml_table_in(conf, "test");
    if (!db) {
        fprintf(stderr, "No [database] section\n");
        toml_free(conf);
        return 1;
    }

    toml_raw_t raw = toml_raw_in(db, "pizda");
    char* pizda;
    if (toml_rtos(raw, &pizda) == 0) {
        printf("Host: %s\n", pizda);
        free((void*)pizda);
    }

    toml_raw_t raw2 = toml_raw_in(db, "piska");
    int64_t piska;
    if (toml_rtoi(raw2, &piska) == 0) {
        printf("Port: %ld\n", piska);
    }

    return 0;
}