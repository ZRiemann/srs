/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2018 Winlin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <ctype.h>
#include <time.h>
#include <srs_kernel_log.hpp>

#include <srs_kernel_error.hpp>

ISrsLog::ISrsLog()
{
}

ISrsLog::~ISrsLog()
{
}

srs_error_t ISrsLog::initialize()
{
    return srs_success;
}

void ISrsLog::reopen()
{
}

void ISrsLog::verbose(const char* /*tag*/, int /*context_id*/, const char* /*fmt*/, ...)
{
}

void ISrsLog::info(const char* /*tag*/, int /*context_id*/, const char* /*fmt*/, ...)
{
}

void ISrsLog::trace(const char* /*tag*/, int /*context_id*/, const char* /*fmt*/, ...)
{
}

void ISrsLog::warn(const char* /*tag*/, int /*context_id*/, const char* /*fmt*/, ...)
{
}

void ISrsLog::error(const char* /*tag*/, int /*context_id*/, const char* /*fmt*/, ...)
{
}

ISrsThreadContext::ISrsThreadContext()
{
}

ISrsThreadContext::~ISrsThreadContext()
{
}

int ISrsThreadContext::generate_id()
{
    return 0;
}

int ISrsThreadContext::get_id()
{
    return 0;
}

int ISrsThreadContext::set_id(int /*v*/)
{
    return 0;
}


void zprint_bin(char *data, int len){
#if ZTRACE_SHORT
    if(isprint(data[0]) &&
       (isspace(data[len -1]) ||
        isprint(data[len - 1])) &&
       (isspace(data[len>>1]) ||
        isprint(data[len>>1]))){
#if ZTRACE_STR_DATA
        int i = (len > 2 )? 2 : len;
        for(i; i < len; ++i){
            if(!isspace(data[i]) && !isprint(data[i])){
                break;
            }
        }

        if(i == len - 1){
            char c = data[len-1];
            data[len-1] = 0;
            printf("string data<len: %d:\n%s", len, data);
            printf("%c\n", c);
            data[len-1] = c;
        }else{
#if ZTRACE_BIN_DATA
        printf("binary data<len: %d>:\n", len);
        int max = len > 256 ? 32 : len;
        int i = 0;
        int j = 32;
        for(i = 0; i < max; ++i, --j){
            if(!j){
                printf("\n");
                j = 32;
            }
            printf("%02x ", (unsigned char)data[i]);
        }
        printf("\n");
#endif /* ZTRACE_BIN_DATA */
        }
#endif /* ZTRACE_STR_DATA */
    }else{
#if ZTRACE_BIN_DATA
        printf("binary data<len: %d>:\n", len);
        int max = len > 256 ? 32 : len;
        int i = 0;
        int j = 32;
        for(i = 0; i < max; ++i, --j){
            if(!j){
                printf("\n");
                j = 32;
            }
            printf("%02x ", (unsigned char)data[i]);
        }
        printf("\n");
#endif /* ZTRACE_BIN_DATA */
    }
#endif /* ZTRACE_SHORT */
}

char *zstr_now(char *buf, int len, int flag){
#if 1
    time_t now;
    struct tm *tmnow = NULL;
    time(&now);
    tmnow = localtime(&now);
#if 1
    switch(flag){
    case 0:
        snprintf(buf, len, "%04d%02d%02d%02d%02d%02d",
                 tmnow->tm_year + 1900, tmnow->tm_mon + 1,
                 tmnow->tm_mday, tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
        break;
    case 1:
        snprintf(buf, len, "%02d%02d%02d",
                 tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
        break;
    default:
        snprintf(buf, len, "%04d%02d%02d%02d%02d%02d",
                 tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);

    }
#endif
#endif
    return buf;
}
