#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define TOTCHRS 800000  /* This is the number of characters we want from the data file. Varies, change to accommodate. */
#define ZHDRWDTH 12     /* Z header word width. */
#define DATFIELDWDTH 8  /* Data field width. */
#define IHDRWDTH 8      /* I header width. */
#define SFIDWDTH 4      /* SFID width. */
#define CONF "CONF"     /* MSO CONF sfid. */
#define CH1 " CH1"      /* MSO Ch1 sfid. */
#define CH2 " CH2"      /* MSO Ch2 sfid. */
#define CH3 " CH3"      /* MSO Ch3 sfid. */
#define CH4 " CH4"      /* MSO Ch4 sfid. */
#define C0EF "C0ef"     /* SPW Msg Success+(ACK) */
#define C0EFMSG ", Msg Success+(ACK), "
#define C034 "C034"     /* SPW AXI Read Response+ */
#define C034MSG ", AXI Read Response+, "
#define C056 "C056"     /* SPW Msg Failure+(NACK) */
#define C056MSG ", Msg Failure+(NACK), "
#define C000 "C000"     /* SPW H&S Telemetry */
#define C000MSG ", H&S Telemetry, "
#define C001 "C001"     /* SPW Mem Read */
#define C001MSG ", Mem Read, "
#define C002 "C002"     /* SPW Engineering Telemetry A */
#define C002MSG ", Engineering Telemetry A, "
#define C019 "C019"     /* SPW Mem Readback */
#define C019MSG ", Mem Readback, "
#define UNDEFMSG ", Undefined Packet Type, "
#define RUMH "RUMH"     /* Space wire RUMH sfid. */


#endif // DEFINE_H_INCLUDED
