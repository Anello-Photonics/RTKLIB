#include "vrs.h"
#include <stdio.h>

static rtcm_t rtcm = { 0 };

static int process_log(const char* fname)
{
    FILE* fLOG = fopen(fname, "rb"); if (!fLOG) return 0;
    int data = 0;
    while (!feof(fLOG))
    {
        if ((data = fgetc(fLOG)) == EOF) break;
        int ret = input_rtcm3(&rtcm, (unsigned char)data);
        if (rtcm.type > 0) /* rtcm data */
        {
            printf("%4i,%4i,%i\n", rtcm.type, rtcm.len + 3, rtcm.crc);
        }
    }
    if (fLOG) fclose(fLOG);
    return 1;
}
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        //process_log("D:\\rtk\\RTKLIB_bin\\bin\\2022-171\\ssr-2022-06-20-w-24-20.log");
    }
    else
    {
        return process_log(argv[1]);
    }
    return 0;
}
