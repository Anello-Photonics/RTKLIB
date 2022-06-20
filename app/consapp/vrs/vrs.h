/* 
* Easy Navigation Technology Inc. (2021)
* By Dr. Yudan Yi
* 2021-2022
*/
#ifndef _VRS_H_
#define _VRS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef WIN_DLL
#define EXPORT __declspec(dllexport) /* for Windows DLL */
#else
#define EXPORT
#endif

/* set default GNSS setting */
#ifndef ENAGLO
#define ENAGLO
#endif

#ifndef ENAGAL
#define ENAGAL
#endif

#ifndef ENACMP
#define ENACMP
#endif

#ifndef ENAQZS
#define ENAQZS
#endif

#ifndef NFREQ
#define NFREQ 5
#endif

#ifndef NEXOBS
#define NEXOBS 3
#endif

#ifndef MAXOBS
#define MAXOBS 96
#endif

#define PI          3.1415926535897932  /* pi */
#define D2R         (PI/180.0)          /* deg to rad */
#define R2D         (180.0/PI)          /* rad to deg */
#define CLIGHT      299792458.0         /* speed of light (m/s) */
#define SC2RAD      3.1415926535898     /* semi-circle to radian (IS-GPS) */
#define AU          149597870691.0      /* 1 AU (m) */
#define AS2R        (D2R/3600.0)        /* arc sec to radian */

#define OMGE        7.2921151467E-5     /* earth angular velocity (IS-GPS) (rad/s) */

#define RE_WGS84    6378137.0           /* earth semimajor axis (WGS84) (m) */
#define FE_WGS84    (1.0/298.257223563) /* earth flattening (WGS84) */

#define SYS_NONE    0x00                /* navigation system: none */
#define SYS_GPS     0x01                /* navigation system: GPS */
#define SYS_SBS     0x02                /* navigation system: SBAS */
#define SYS_GLO     0x04                /* navigation system: GLONASS */
#define SYS_GAL     0x08                /* navigation system: Galileo */
#define SYS_QZS     0x10                /* navigation system: QZSS */
#define SYS_CMP     0x20                /* navigation system: BeiDou */
#define SYS_IRN     0x40                /* navigation system: IRNS */
#define SYS_LEO     0x80                /* navigation system: LEO */
#define SYS_ALL     0xFF                /* navigation system: all */

#define MINPRNGPS   1                   /* min satellite PRN number of GPS */
#define MAXPRNGPS   32                  /* max satellite PRN number of GPS */
#define NSATGPS     (MAXPRNGPS-MINPRNGPS+1) /* number of GPS satellites */
#define NSYSGPS     1

#ifdef ENAGLO
#define MINPRNGLO   1                   /* min satellite slot number of GLONASS */
#define MAXPRNGLO   27                  /* max satellite slot number of GLONASS */
#define NSATGLO     (MAXPRNGLO-MINPRNGLO+1) /* number of GLONASS satellites */
#define NSYSGLO     1
#else
#define MINPRNGLO   0
#define MAXPRNGLO   0
#define NSATGLO     0
#define NSYSGLO     0
#endif
#ifdef ENAGAL
#define MINPRNGAL   1                   /* min satellite PRN number of Galileo */
/* increase to accomodate new galileo launch recently (2022) */
#define MAXPRNGAL   40                  /* max satellite PRN number of Galileo */ 
#define NSATGAL    (MAXPRNGAL-MINPRNGAL+1) /* number of Galileo satellites */
#define NSYSGAL     1
#else
#define MINPRNGAL   0
#define MAXPRNGAL   0
#define NSATGAL     0
#define NSYSGAL     0
#endif
#ifdef ENAQZS
#define MINPRNQZS   193                 /* min satellite PRN number of QZSS */
#define MAXPRNQZS   202                 /* max satellite PRN number of QZSS */
#define MINPRNQZS_S 183                 /* min satellite PRN number of QZSS L1S */
#define MAXPRNQZS_S 191                 /* max satellite PRN number of QZSS L1S */
#define NSATQZS     (MAXPRNQZS-MINPRNQZS+1) /* number of QZSS satellites */
#define NSYSQZS     1
#else
#define MINPRNQZS   0
#define MAXPRNQZS   0
#define MINPRNQZS_S 0
#define MAXPRNQZS_S 0
#define NSATQZS     0
#define NSYSQZS     0
#endif
#ifdef ENACMP
#define MINPRNCMP   1                   /* min satellite sat number of BeiDou */
#define MAXPRNCMP   63                  /* max satellite sat number of BeiDou */
#define NSATCMP     (MAXPRNCMP-MINPRNCMP+1) /* number of BeiDou satellites */
#define NSYSCMP     1
#else
#define MINPRNCMP   0
#define MAXPRNCMP   0
#define NSATCMP     0
#define NSYSCMP     0
#endif

#define NSYS        (NSYSGPS+NSYSGLO+NSYSGAL+NSYSQZS+NSYSCMP) /* number of systems */

#define MAXSAT      (NSATGPS+NSATGLO+NSATGAL+NSATQZS+NSATCMP)
                                        /* max satellite number (1 to MAXSAT) */
#define MAXDTOE     7200.0              /* max time difference to GPS Toe (s) */
#define MAXDTOE_QZS 7200.0              /* max time difference to QZSS Toe (s) */
#define MAXDTOE_GAL 14400.0             /* max time difference to Galileo Toe (s) */
#define MAXDTOE_CMP 21600.0             /* max time difference to BeiDou Toe (s) */
#define MAXDTOE_GLO 1800.0              /* max time difference to GLONASS Toe (s) */
#define MAXDTOE_IRN 7200.0              /* max time difference to IRNSS Toe (s) */
#define MAXDTOE_SBS 360.0               /* max time difference to SBAS Toe (s) */
#define MAXDTOE_S   86400.0             /* max time difference to ephem toe (s) for other */

#define CODE_NONE   0                   /* obs code: none or unknown */
#define CODE_L1C    1                   /* obs code: L1C/A,G1C/A,E1C (GPS,GLO,GAL,QZS,SBS) */
#define CODE_L1P    2                   /* obs code: L1P,G1P,B1P (GPS,GLO,BDS) */
#define CODE_L1W    3                   /* obs code: L1 Z-track (GPS) */
#define CODE_L1Y    4                   /* obs code: L1Y        (GPS) */
#define CODE_L1M    5                   /* obs code: L1M        (GPS) */
#define CODE_L1N    6                   /* obs code: L1codeless,B1codeless (GPS,BDS) */
#define CODE_L1S    7                   /* obs code: L1C(D)     (GPS,QZS) */
#define CODE_L1L    8                   /* obs code: L1C(P)     (GPS,QZS) */
#define CODE_L1E    9                   /* (not used) */
#define CODE_L1A    10                  /* obs code: E1A,B1A    (GAL,BDS) */
#define CODE_L1B    11                  /* obs code: E1B        (GAL) */
#define CODE_L1X    12                  /* obs code: E1B+C,L1C(D+P),B1D+P (GAL,QZS,BDS) */
#define CODE_L1Z    13                  /* obs code: E1A+B+C,L1S (GAL,QZS) */
#define CODE_L2C    14                  /* obs code: L2C/A,G1C/A (GPS,GLO) */
#define CODE_L2D    15                  /* obs code: L2 L1C/A-(P2-P1) (GPS) */
#define CODE_L2S    16                  /* obs code: L2C(M)     (GPS,QZS) */
#define CODE_L2L    17                  /* obs code: L2C(L)     (GPS,QZS) */
#define CODE_L2X    18                  /* obs code: L2C(M+L),B1_2I+Q (GPS,QZS,BDS) */
#define CODE_L2P    19                  /* obs code: L2P,G2P    (GPS,GLO) */
#define CODE_L2W    20                  /* obs code: L2 Z-track (GPS) */
#define CODE_L2Y    21                  /* obs code: L2Y        (GPS) */
#define CODE_L2M    22                  /* obs code: L2M        (GPS) */
#define CODE_L2N    23                  /* obs code: L2codeless (GPS) */
#define CODE_L5I    24                  /* obs code: L5I,E5aI   (GPS,GAL,QZS,SBS) */
#define CODE_L5Q    25                  /* obs code: L5Q,E5aQ   (GPS,GAL,QZS,SBS) */
#define CODE_L5X    26                  /* obs code: L5I+Q,E5aI+Q,L5B+C,B2aD+P (GPS,GAL,QZS,IRN,SBS,BDS) */
#define CODE_L7I    27                  /* obs code: E5bI,B2bI  (GAL,BDS) */
#define CODE_L7Q    28                  /* obs code: E5bQ,B2bQ  (GAL,BDS) */
#define CODE_L7X    29                  /* obs code: E5bI+Q,B2bI+Q (GAL,BDS) */
#define CODE_L6A    30                  /* obs code: E6A,B3A    (GAL,BDS) */
#define CODE_L6B    31                  /* obs code: E6B        (GAL) */
#define CODE_L6C    32                  /* obs code: E6C        (GAL) */
#define CODE_L6X    33                  /* obs code: E6B+C,LEXS+L,B3I+Q (GAL,QZS,BDS) */
#define CODE_L6Z    34                  /* obs code: E6A+B+C,L6D+E (GAL,QZS) */
#define CODE_L6S    35                  /* obs code: L6S        (QZS) */
#define CODE_L6L    36                  /* obs code: L6L        (QZS) */
#define CODE_L8I    37                  /* obs code: E5abI      (GAL) */
#define CODE_L8Q    38                  /* obs code: E5abQ      (GAL) */
#define CODE_L8X    39                  /* obs code: E5abI+Q,B2abD+P (GAL,BDS) */
#define CODE_L2I    40                  /* obs code: B1_2I      (BDS) */
#define CODE_L2Q    41                  /* obs code: B1_2Q      (BDS) */
#define CODE_L6I    42                  /* obs code: B3I        (BDS) */
#define CODE_L6Q    43                  /* obs code: B3Q        (BDS) */
#define CODE_L3I    44                  /* obs code: G3I        (GLO) */
#define CODE_L3Q    45                  /* obs code: G3Q        (GLO) */
#define CODE_L3X    46                  /* obs code: G3I+Q      (GLO) */
#define CODE_L1I    47                  /* obs code: B1I        (BDS) (obsolute) */
#define CODE_L1Q    48                  /* obs code: B1Q        (BDS) (obsolute) */
#define CODE_L5A    49                  /* obs code: L5A SPS    (IRN) */
#define CODE_L5B    50                  /* obs code: L5B RS(D)  (IRN) */
#define CODE_L5C    51                  /* obs code: L5C RS(P)  (IRN) */
#define CODE_L9A    52                  /* obs code: SA SPS     (IRN) */
#define CODE_L9B    53                  /* obs code: SB RS(D)   (IRN) */
#define CODE_L9C    54                  /* obs code: SC RS(P)   (IRN) */
#define CODE_L9X    55                  /* obs code: SB+C       (IRN) */
#define CODE_L1D    56                  /* obs code: B1D        (BDS) */
#define CODE_L5D    57                  /* obs code: L5D(L5S),B2aD (QZS,BDS) */
#define CODE_L5P    58                  /* obs code: L5P(L5S),B2aP (QZS,BDS) */
#define CODE_L5Z    59                  /* obs code: L5D+P(L5S) (QZS) */
#define CODE_L6E    60                  /* obs code: L6E        (QZS) */
#define CODE_L7D    61                  /* obs code: B2bD       (BDS) */
#define CODE_L7P    62                  /* obs code: B2bP       (BDS) */
#define CODE_L7Z    63                  /* obs code: B2bD+P     (BDS) */
#define CODE_L8D    64                  /* obs code: B2abD      (BDS) */
#define CODE_L8P    65                  /* obs code: B2abP      (BDS) */
#define CODE_L4A    66                  /* obs code: G1aL1OCd   (GLO) */
#define CODE_L4B    67                  /* obs code: G1aL1OCd   (GLO) */
#define CODE_L4X    68                  /* obs code: G1al1OCd+p (GLO) */
#define MAXCODE     68                  /* max number of obs code */

#define MAXANT      64                  /* max length of station name/antenna type */

#define P2_5        0.03125             /* 2^-5 */
#define P2_6        0.015625            /* 2^-6 */
#define P2_11       4.882812500000000E-04 /* 2^-11 */
#define P2_15       3.051757812500000E-05 /* 2^-15 */
#define P2_17       7.629394531250000E-06 /* 2^-17 */
#define P2_19       1.907348632812500E-06 /* 2^-19 */
#define P2_20       9.536743164062500E-07 /* 2^-20 */
#define P2_21       4.768371582031250E-07 /* 2^-21 */
#define P2_23       1.192092895507810E-07 /* 2^-23 */
#define P2_24       5.960464477539063E-08 /* 2^-24 */
#define P2_27       7.450580596923828E-09 /* 2^-27 */
#define P2_29       1.862645149230957E-09 /* 2^-29 */
#define P2_30       9.313225746154785E-10 /* 2^-30 */
#define P2_31       4.656612873077393E-10 /* 2^-31 */
#define P2_32       2.328306436538696E-10 /* 2^-32 */
#define P2_33       1.164153218269348E-10 /* 2^-33 */
#define P2_35       2.910383045673370E-11 /* 2^-35 */
#define P2_38       3.637978807091710E-12 /* 2^-38 */
#define P2_39       1.818989403545856E-12 /* 2^-39 */
#define P2_40       9.094947017729280E-13 /* 2^-40 */
#define P2_43       1.136868377216160E-13 /* 2^-43 */
#define P2_48       3.552713678800501E-15 /* 2^-48 */
#define P2_50       8.881784197001252E-16 /* 2^-50 */
#define P2_55       2.775557561562891E-17 /* 2^-55 */

#define FREQ1       1.57542E9           /* L1/E1/B1C  frequency (Hz) */
#define FREQ2       1.22760E9           /* L2         frequency (Hz) */
#define FREQ5       1.17645E9           /* L5/E5a/B2a frequency (Hz) */
#define FREQ6       1.27875E9           /* E6/L6  frequency (Hz) */
#define FREQ7       1.20714E9           /* E5b    frequency (Hz) */
#define FREQ8       1.191795E9          /* E5a+b  frequency (Hz) */
#define FREQ9       2.492028E9          /* S      frequency (Hz) */
#define FREQ1_GLO   1.60200E9           /* GLONASS G1 base frequency (Hz) */
#define DFRQ1_GLO   0.56250E6           /* GLONASS G1 bias frequency (Hz/n) */
#define FREQ2_GLO   1.24600E9           /* GLONASS G2 base frequency (Hz) */
#define DFRQ2_GLO   0.43750E6           /* GLONASS G2 bias frequency (Hz/n) */
#define FREQ3_GLO   1.202025E9          /* GLONASS G3 frequency (Hz) */
#define FREQ1a_GLO  1.600995E9          /* GLONASS G1a frequency (Hz) */
#define FREQ2a_GLO  1.248060E9          /* GLONASS G2a frequency (Hz) */
#define FREQ1_CMP   1.561098E9          /* BDS B1I     frequency (Hz) */
#define FREQ2_CMP   1.20714E9           /* BDS B2I/B2b frequency (Hz) */
#define FREQ3_CMP   1.26852E9           /* BDS B3      frequency (Hz) */

#define MAXFREQ     7                   /* max NFREQ */

/* type definitions ----------------------------------------------------------*/

typedef struct {        /* time struct */
    time_t time;        /* time (s) expressed by standard time_t */
    double sec;         /* fraction of second under 1 s */
} gtime_t;

typedef struct {        /* observation data record */
    gtime_t time;       /* receiver sampling time (GPST) */
    uint8_t sat, rcv;    /* satellite/receiver number */
    uint16_t SNR[NFREQ + NEXOBS]; /* signal strength (0.001 dBHz) */
    uint8_t  LLI[NFREQ + NEXOBS]; /* loss of lock indicator */
    uint8_t code[NFREQ + NEXOBS]; /* code indicator (CODE_???) */
    double L[NFREQ + NEXOBS]; /* observation data carrier-phase (cycle) */
    double P[NFREQ + NEXOBS]; /* observation data pseudorange (m) */
    float  D[NFREQ + NEXOBS]; /* observation data doppler frequency (Hz) */
} obsd_t;

typedef struct {        /* observation data */
    int n, nmax;         /* number of obervation data/allocated */
    obsd_t data[MAXOBS];       /* observation data records */
} obs_t;


typedef struct {        /* GPS/QZS/GAL broadcast ephemeris type */
    int sat;            /* satellite number */
    int iode, iodc;      /* IODE,IODC */
    int sva;            /* SV accuracy (URA index) */
    int svh;            /* SV health (0:ok) */
    int week;           /* GPS/QZS: gps week, GAL: galileo week */
    int code;           /* GPS/QZS: code on L2 */
                        /* GAL: data source defined as rinex 3.03 */
                        /* BDS: data source (0:unknown,1:B1I,2:B1Q,3:B2I,4:B2Q,5:B3I,6:B3Q) */
    int flag;           /* GPS/QZS: L2 P data flag */
                        /* BDS: nav type (0:unknown,1:IGSO/MEO,2:GEO) */
    gtime_t toe, toc, ttr; /* Toe,Toc,T_trans */
                        /* SV orbit parameters */
    double A, e, i0, OMG0, omg, M0, deln, OMGd, idot;
    double crc, crs, cuc, cus, cic, cis;
    double toes;        /* Toe (s) in week */
    double fit;         /* fit interval (h) */
    double f0, f1, f2;    /* SV clock parameters (af0,af1,af2) */
    double tgd[6];      /* group delay parameters */
                        /* GPS/QZS:tgd[0]=TGD */
                        /* GAL:tgd[0]=BGD_E1E5a,tgd[1]=BGD_E1E5b */
                        /* CMP:tgd[0]=TGD_B1I ,tgd[1]=TGD_B2I/B2b,tgd[2]=TGD_B1Cp */
                        /*     tgd[3]=TGD_B2ap,tgd[4]=ISC_B1Cd   ,tgd[5]=ISC_B2ad */
    double Adot, ndot;   /* Adot,ndot for CNAV */
} eph_t;

typedef struct {        /* GLONASS broadcast ephemeris type */
    int sat;            /* satellite number */
    int iode;           /* IODE (0-6 bit of tb field) */
    int frq;            /* satellite frequency number */
    int svh, sva, age;    /* satellite health, accuracy, age of operation */
    gtime_t toe;        /* epoch of epherides (gpst) */
    gtime_t tof;        /* message frame time (gpst) */
    double pos[3];      /* satellite position (ecef) (m) */
    double vel[3];      /* satellite velocity (ecef) (m/s) */
    double acc[3];      /* satellite acceleration (ecef) (m/s^2) */
    double taun, gamn;   /* SV clock bias (s)/relative freq bias */
    double dtaun;       /* delay between L1 and L2 (s) */
} geph_t;

typedef struct {        /* SSR correction type */
    gtime_t t0[6];      /* epoch time (GPST) {eph,clk,hrclk,ura,bias,pbias} */
    double udi[6];      /* SSR update interval (s) */
    int iod[6];         /* iod ssr {eph,clk,hrclk,ura,bias,pbias} */
    int iode;           /* issue of data */
    int iodcrc;         /* issue of data crc for beidou/sbas */
    int ura;            /* URA indicator */
    int refd;           /* sat ref datum (0:ITRF,1:regional) */
    double deph[3];    /* delta orbit {radial,along,cross} (m) */
    double ddeph[3];    /* dot delta orbit {radial,along,cross} (m/s) */
    double dclk[3];    /* delta clock {c0,c1,c2} (m,m/s,m/s^2) */
    double hrclk;       /* high-rate clock corection (m) */
    float  cbias[MAXCODE]; /* code biases (m) */
    double pbias[MAXCODE]; /* phase biases (m) */
    float  stdpb[MAXCODE]; /* std-dev of phase biases (m) */
    double yaw_ang, yaw_rate; /* yaw angle and yaw rate (deg,deg/s) */
    uint8_t update;     /* update flag (0:no update,1:update) */
} ssr_t;

typedef struct {        /* antenna parameter type */
    int sat;            /* satellite number (0:receiver) */
    char type[MAXANT];  /* antenna type */
    char code[MAXANT];  /* serial number or satellite code */
    gtime_t ts, te;      /* valid time start and end */
    double off[NFREQ][3]; /* phase center offset e/n/u or x/y/z (m) */
    double var[NFREQ][19]; /* phase center variation (m) */
                        /* el=90,85,...,0 or nadir=0,1,2,3,... (deg) */
} pcv_t;

typedef struct {        /* antenna parameters type */
    int n, nmax;         /* number of data/allocated */
    pcv_t* pcv;         /* antenna parameters data */
} pcvs_t;

typedef struct {        /* navigation data type */
    int n, nmax;         /* number of broadcast ephemeris */
    int ng, ngmax;       /* number of glonass ephemeris */
    int ns, nsmax;       /* number of sbas ephemeris */
    int ne, nemax;       /* number of precise ephemeris */
    int nc, ncmax;       /* number of precise clock */
    int na, namax;       /* number of almanac data */
    int nt, ntmax;       /* number of tec grid data */
    eph_t eph[MAXSAT];         /* GPS/QZS/GAL/BDS/IRN ephemeris */
    geph_t geph[NSATGLO];       /* GLONASS ephemeris */
    double utc_gps[8];  /* GPS delta-UTC parameters {A0,A1,Tot,WNt,dt_LS,WN_LSF,DN,dt_LSF} */
    double utc_glo[8];  /* GLONASS UTC time parameters {tau_C,tau_GPS} */
    double utc_gal[8];  /* Galileo UTC parameters */
    double utc_qzs[8];  /* QZS UTC parameters */
    double utc_cmp[8];  /* BeiDou UTC parameters */
    double utc_irn[9];  /* IRNSS UTC parameters {A0,A1,Tot,...,dt_LSF,A2} */
    double utc_sbs[4];  /* SBAS UTC parameters */
    double ion_gps[8];  /* GPS iono model parameters {a0,a1,a2,a3,b0,b1,b2,b3} */
    double ion_gal[4];  /* Galileo iono model parameters {ai0,ai1,ai2,0} */
    double ion_qzs[8];  /* QZSS iono model parameters {a0,a1,a2,a3,b0,b1,b2,b3} */
    double ion_cmp[8];  /* BeiDou iono model parameters {a0,a1,a2,a3,b0,b1,b2,b3} */
    double ion_irn[8];  /* IRNSS iono model parameters {a0,a1,a2,a3,b0,b1,b2,b3} */
    int glo_fcn[32];    /* GLONASS FCN + 8 */
    double cbias[MAXSAT][3]; /* satellite DCB (0:P1-P2,1:P1-C1,2:P2-C2) (m) */
    pcv_t pcvs[MAXSAT]; /* satellite antenna pcv */
    ssr_t ssr[MAXSAT];  /* SSR corrections */
} nav_t;

typedef struct {        /* station parameter type */
    char name[MAXANT]; /* marker name */
    char marker[MAXANT]; /* marker number */
    char antdes[MAXANT]; /* antenna descriptor */
    char antsno[MAXANT]; /* antenna serial number */
    char rectype[MAXANT]; /* receiver type descriptor */
    char recver[MAXANT]; /* receiver firmware version */
    char recsno[MAXANT]; /* receiver serial number */
    int antsetup;       /* antenna setup id */
    int itrf;           /* ITRF realization year */
    int deltype;        /* antenna delta type (0:enu,1:xyz) */
    double pos[3];      /* station position (ecef) (m) */
    double del[3];      /* antenna position delta (e/n/u or x/y/z) (m) */
    double hgt;         /* antenna height (m) */
    int glo_cp_align;   /* GLONASS code-phase alignment (0:no,1:yes) */
    double glo_cp_bias[4]; /* GLONASS code-phase biases {1C,1P,2C,2P} (m) */
} sta_t;

typedef struct {        /* RTCM control struct type */
    int staid;          /* station id */
    int stah;           /* station health */
    int seqno;          /* sequence number for rtcm 2 or iods msm */
    int outtype;        /* output message type */
    gtime_t time;       /* message time */
    gtime_t time_s;     /* message start time */
    obs_t obs;          /* observation data (uncorrected) */
    nav_t nav;          /* satellite ephemerides */
    sta_t sta;          /* station parameters */
    ssr_t ssr[MAXSAT];  /* output of ssr corrections */
    char msg[128];      /* special message */
    char msgtype[256];  /* last message type */
    char msmtype[7][128]; /* msm signal types */
    int obsflag;        /* obs data complete flag (1:ok,0:not complete) */
    int ephsat;         /* input ephemeris satellite number */
    int ephset;         /* input ephemeris set (0-1) */
    double cp[MAXSAT][NFREQ + NEXOBS]; /* carrier-phase measurement */
    uint16_t lock[MAXSAT][NFREQ + NEXOBS]; /* lock time */
    uint16_t loss[MAXSAT][NFREQ + NEXOBS]; /* loss of lock count */
    gtime_t lltime[MAXSAT][NFREQ + NEXOBS]; /* last lock time */
    int nbyte;          /* number of bytes in message buffer */
    int nbit;           /* number of bits in word buffer */
    int len;            /* message length (bytes) */
    uint8_t buff[1200]; /* message buffer */
    uint32_t word;      /* word buffer for rtcm 2 */
    uint32_t nmsg2[100]; /* message count of RTCM 2 (1-99:1-99,0:other) */
    uint32_t nmsg3[400]; /* message count of RTCM 3 (1-299:1001-1299,300-329:4070-4099,0:ohter) */
    char opt[256];      /* RTCM dependent options */
} rtcm_t;

/* satellites, systems, codes functions --------------------------------------*/
EXPORT int  satno(int sys, int prn);
EXPORT int  satsys(int sat, int* prn);
EXPORT int  satid2no(const char* id);
EXPORT void satno2id(int sat, char* id);
EXPORT uint8_t obs2code(const char* obs);
EXPORT char* code2obs(uint8_t code);
EXPORT double code2freq(int sys, uint8_t code, int fcn);
EXPORT double sat2freq(int sat, uint8_t code, const nav_t* nav);
EXPORT int  code2idx(int sys, uint8_t code);
EXPORT void setcodepri(int sys, int idx, const char* pri);
EXPORT int  getcodepri(int sys, uint8_t code, const char* opt);

/* time and string functions -------------------------------------------------*/
EXPORT double  str2num(const char* s, int i, int n);
EXPORT int     str2time(const char* s, int i, int n, gtime_t* t);
EXPORT void    time2str(gtime_t t, char* str, int n);
EXPORT gtime_t epoch2time(const double* ep);
EXPORT void    time2epoch(gtime_t t, double* ep);
EXPORT gtime_t gpst2time(int week, double sec);
EXPORT double  time2gpst(gtime_t t, int* week);
EXPORT gtime_t gst2time(int week, double sec);
EXPORT double  time2gst(gtime_t t, int* week);
EXPORT gtime_t bdt2time(int week, double sec);
EXPORT double  time2bdt(gtime_t t, int* week);
EXPORT char* time_str(gtime_t t, int n);

EXPORT gtime_t timeadd(gtime_t t, double sec);
EXPORT double  timediff(gtime_t t1, gtime_t t2);
EXPORT gtime_t gpst2utc(gtime_t t);
EXPORT gtime_t utc2gpst(gtime_t t);
EXPORT gtime_t gpst2bdt(gtime_t t);
EXPORT gtime_t bdt2gpst(gtime_t t);
EXPORT gtime_t timeget(void);
EXPORT void    timeset(gtime_t t);
EXPORT void    timereset(void);
EXPORT double  time2doy(gtime_t t);
EXPORT double  utc2gmst(gtime_t t, double ut1_utc);

EXPORT int adjgpsweek(int week);

/* coordinates transformation ------------------------------------------------*/
EXPORT void ecef2pos(const double* r, double* pos);
EXPORT void pos2ecef(const double* pos, double* r);
EXPORT void ecef2enu(const double* pos, const double* r, double* e);
EXPORT void enu2ecef(const double* pos, const double* e, double* r);
EXPORT void covenu(const double* pos, const double* P, double* Q);
EXPORT void covecef(const double* pos, const double* Q, double* P);
EXPORT void xyz2enu(const double* pos, double* E);
EXPORT void eci2ecef(gtime_t tutc, const double* erpv, double* U, double* gmst);
EXPORT void deg2dms(double deg, double* dms, int ndec);
EXPORT double dms2deg(const double* dms);

/* debug trace functions -----------------------------------------------------*/
EXPORT void traceopen(const char* file);
EXPORT void traceclose(void);
EXPORT void tracelevel(int level);
EXPORT void trace(int level, const char* format, ...);
EXPORT void traceobs(int level, const obsd_t* obs, int n);
EXPORT void tracenav(int level, const nav_t* nav);
EXPORT void tracegnav(int level, const nav_t* nav);

/* positioning models --------------------------------------------------------*/
EXPORT double satazel(const double* pos, const double* e, double* azel);
EXPORT double geodist(const double* rs, const double* rr, double* e);
EXPORT void dops(int ns, const double* azel, double elmin, double* dop);

/* atmosphere models ---------------------------------------------------------*/
EXPORT double ionmodel(gtime_t t, const double* ion, const double* pos,
    const double* azel);
EXPORT double ionmapf(const double* pos, const double* azel);
EXPORT double ionppp(const double* pos, const double* azel, double re,
    double hion, double* pppos);
EXPORT double tropmodel(gtime_t time, const double* pos, const double* azel,
    double humi);
EXPORT double tropmapf(gtime_t time, const double* pos, const double* azel,
    double* mapfw);

/* antenna models ------------------------------------------------------------*/
EXPORT void antmodel(const pcv_t* pcv, const double* del, const double* azel,
    int opt, double* dant);
EXPORT void antmodel_s(const pcv_t* pcv, double nadir, double* dant);

/* earth tide models ---------------------------------------------------------*/
EXPORT void sunmoonpos(gtime_t tutc, const double* erpv, double* rsun,
    double* rmoon, double* gmst);
EXPORT void tidedisp(gtime_t tutc, const double* rr, int opt, const erp_t* erp,
    const double* odisp, double* dr);

/* ephemeris and clock functions ---------------------------------------------*/
EXPORT double eph2clk(gtime_t time, const eph_t* eph);
EXPORT double geph2clk(gtime_t time, const geph_t* geph);
EXPORT void eph2pos(gtime_t time, const eph_t* eph, double* rs, double* dts, double* var);
EXPORT void geph2pos(gtime_t time, const geph_t* geph, double* rs, double* dts, double* var);
EXPORT void satantoff(gtime_t time, const double* rs, int sat, const nav_t* nav, double* dant);
EXPORT int  satpos(gtime_t time, gtime_t teph, int sat, int ephopt, const nav_t* nav, double* rs, double* dts, double* var, int* svh);
EXPORT void satposs(gtime_t time, const obsd_t* obs, int n, const nav_t* nav, int sateph, double* rs, double* dts, double* var, int* svh);
EXPORT void setseleph(int sys, int sel);
EXPORT int  getseleph(int sys);

/* receiver raw data functions -----------------------------------------------*/
EXPORT uint32_t getbitu(const uint8_t* buff, int pos, int len);
EXPORT int32_t  getbits(const uint8_t* buff, int pos, int len);
EXPORT void setbitu(uint8_t* buff, int pos, int len, uint32_t data);
EXPORT void setbits(uint8_t* buff, int pos, int len, int32_t  data);
EXPORT uint32_t rtk_crc32(const uint8_t* buff, int len);
EXPORT uint32_t rtk_crc24q(const uint8_t* buff, int len);
EXPORT uint16_t rtk_crc16(const uint8_t* buff, int len);

/* matrix and vector functions -----------------------------------------------*/
EXPORT double* mat(int n, int m);
EXPORT int* imat(int n, int m);
EXPORT double* zeros(int n, int m);
EXPORT double* eye(int n);
EXPORT double dot(const double* a, const double* b, int n);
EXPORT double norm(const double* a, int n);
EXPORT void cross3(const double* a, const double* b, double* c);
EXPORT int  normv3(const double* a, double* b);
EXPORT void matcpy(double* A, const double* B, int n, int m);
EXPORT void matmul(const char* tr, int n, int k, int m, double alpha, const double* A, const double* B, double beta, double* C);

EXPORT int input_rtcm2(rtcm_t* rtcm, uint8_t data);
EXPORT int input_rtcm3(rtcm_t* rtcm, uint8_t data);
EXPORT int gen_rtcm2(rtcm_t* rtcm, int type, int sync);
EXPORT int gen_rtcm3(rtcm_t* rtcm, int type, int subtype, int sync);

/* integer ambiguity resolution ----------------------------------------------*/
EXPORT int lambda(int n, int m, const double* a, const double* Q, double* F, double* s);
EXPORT int lambda_reduction(int n, const double* Q, double* Z);
EXPORT int lambda_search(int n, int m, const double* a, const double* Q, double* F, double* s);

#ifdef __cplusplus
}
#endif
#endif
