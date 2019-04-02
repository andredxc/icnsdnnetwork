/*****************************************************************************/
/*                                                                           */
/* Copyright notice: please read file license.txt in the NetBee root folder. */
/*                                                                           */
/*****************************************************************************/


%option batch
%option nounput

char      [^\r\n]
decnumber [0-9]+
hexnumber 0x[0-9a-fA-F]+
var       [a-zA-Z_][a-zA-Z_0-9]*
address   [a-z_0-9]+(\.[a-z_0-9]*)*
dotquad	  ([0-9]{1,3}\.){3}([0-9]{1,3})
colquad	  ([0-9a-fA-F]{2}:){3}([0-9a-fA-F]{2})
newline   (\r|\n|\r\n)
string    "\""[^\"]*"\""

%{

#include <nbnetvm.h>
#include "nvm_gramm.tab.h"
#include "../opcodes.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#ifdef WIN32
#define fileno _fileno
#endif

#define YY_NO_INPUT

#ifdef FLEX_SCANNER
#define YY_NO_UNPUT
static YY_BUFFER_STATE in_buffer;
#else
static char *in_buffer;

#undef getc
#define getc(fp)  (*in_buffer == 0 ? EOF : *in_buffer++)
#endif

extern int eline;
extern int nvmparser_error(const char *s);

#define YY_NO_UNPUT
static YY_BUFFER_STATE in_buffer;

int32_t str2int(const char *s, uint32_t *num, uint8_t base);

%}

%%

segment			return SEGMENT;
ends			return ENDS;
ip_host			return T_HOST;
tcp_port		return T_PORT;
\.locals		return LOCALS;
\.maxstacksize		return STACKSIZE;
\.byte_order		return BYTEORDER;

\.datamem_size		return DATAMEMSIZE;
\.netpe_name		return NETPENAME;
\.info_size		return INFOPARTSIZE;
\.use_coprocessor	return COPRO_DECL;

"spload.8"		{nvmparser_lval.number =  PBLDS; return T_NO_ARG_INST;}
"upload.8"		{nvmparser_lval.number =  PBLDU; return T_NO_ARG_INST;}
"spload.16"		{nvmparser_lval.number =  PSLDS; return T_NO_ARG_INST;}
"upload.16"		{nvmparser_lval.number =  PSLDU; return T_NO_ARG_INST;}
"spload.32"		{nvmparser_lval.number =  PILD; return T_NO_ARG_INST;}
"smload.8"		{nvmparser_lval.number =  DBLDS; return T_NO_ARG_INST;}
"umload.8"		{nvmparser_lval.number =  DBLDU; return T_NO_ARG_INST;}
"smload.16"		{nvmparser_lval.number =  DSLDS; return T_NO_ARG_INST;}
"umload.16"		{nvmparser_lval.number =  DSLDU; return T_NO_ARG_INST;}
"umload.32"		{nvmparser_lval.number =  DILD; return T_NO_ARG_INST;}
"ssload.8"		{nvmparser_lval.number =  SBLDS; return T_NO_ARG_INST;}
"usload.8"		{nvmparser_lval.number =  SBLDU; return T_NO_ARG_INST;}
"ssload.16"		{nvmparser_lval.number =  SSLDS; return T_NO_ARG_INST;}
"usload.16"		{nvmparser_lval.number =  SSLDU; return T_NO_ARG_INST;}
"ssload.32"		{nvmparser_lval.number =  SILD; return T_NO_ARG_INST;}
"iplen"			{nvmparser_lval.number =  BPLOAD_IH; return T_NO_ARG_INST;}
"mstore.8"		{nvmparser_lval.number =  DBSTR; return T_NO_ARG_INST;}
"mstore.16"		{nvmparser_lval.number =  DSSTR; return T_NO_ARG_INST;}
"mstore.32"		{nvmparser_lval.number =  DISTR; return T_NO_ARG_INST;}
"pstore.8"		{nvmparser_lval.number =  PBSTR; return T_NO_ARG_INST;}
"pstore.16"		{nvmparser_lval.number =  PSSTR; return T_NO_ARG_INST;}
"pstore.32"		{nvmparser_lval.number =  PISTR; return T_NO_ARG_INST;}
"sstore.8"		{nvmparser_lval.number =  SBSTR; return T_NO_ARG_INST;}
"sstore.16"		{nvmparser_lval.number =  SSSTR; return T_NO_ARG_INST;}
"sstore.32"		{nvmparser_lval.number =  SISTR; return T_NO_ARG_INST;}
"istore.8"		{nvmparser_lval.number =  IBSTR; return T_NO_ARG_INST;}
"istore.16"		{nvmparser_lval.number =  ISSTR; return T_NO_ARG_INST;}
"istore.32"		{nvmparser_lval.number =  IISTR; return T_NO_ARG_INST;}
"uiload.8"		{nvmparser_lval.number =  ISBLD; return T_NO_ARG_INST;}
"uiload.16"		{nvmparser_lval.number =  ISSLD; return T_NO_ARG_INST;}
"siload.8"		{nvmparser_lval.number =  ISSBLD; return T_NO_ARG_INST;}
"siload.16"		{nvmparser_lval.number =  ISSSLD; return T_NO_ARG_INST;}
"siload.32"		{nvmparser_lval.number =  ISSILD; return T_NO_ARG_INST;}
"add"			{nvmparser_lval.number =  ADD; return T_NO_ARG_INST;}
"add.s"			{nvmparser_lval.number =  ADDSOV; return T_NO_ARG_INST;}
"add.u"			{nvmparser_lval.number =  ADDUOV; return T_NO_ARG_INST;}
"sub"			{nvmparser_lval.number =  SUB; return T_NO_ARG_INST;}
"sub.s"			{nvmparser_lval.number =  SUBSOV; return T_NO_ARG_INST;}
"sub.u"			{nvmparser_lval.number =  SUBUOV; return T_NO_ARG_INST;}
"mul"			{nvmparser_lval.number =  IMUL; return T_NO_ARG_INST;}
"muls.ovf"		{nvmparser_lval.number =  IMULSOV; return T_NO_ARG_INST;}
"mul.ovf"		{nvmparser_lval.number =  IMULUOV; return T_NO_ARG_INST;}
"mod"			{nvmparser_lval.number =  MOD; return T_NO_ARG_INST;}
"neg"			{nvmparser_lval.number =  NEG; return T_NO_ARG_INST;}
"or"			{nvmparser_lval.number =  OR; return T_NO_ARG_INST;}
"and"			{nvmparser_lval.number =  AND; return T_NO_ARG_INST;}
"xor"			{nvmparser_lval.number =  XOR; return T_NO_ARG_INST;}
"not"			{nvmparser_lval.number =  NOT; return T_NO_ARG_INST;}
"inc1"			{nvmparser_lval.number =  IINC_1; return T_NO_ARG_INST;}
"inc2"			{nvmparser_lval.number =  IINC_2; return T_NO_ARG_INST;}
"inc3"			{nvmparser_lval.number =  IINC_3; return T_NO_ARG_INST;}
"inc4"			{nvmparser_lval.number =  IINC_4; return T_NO_ARG_INST;}
"dec1"			{nvmparser_lval.number =  IDEC_1; return T_NO_ARG_INST;}
"dec2"			{nvmparser_lval.number =  IDEC_2; return T_NO_ARG_INST;}
"dec3"			{nvmparser_lval.number =  IDEC_3; return T_NO_ARG_INST;}
"dec4"			{nvmparser_lval.number =  IDEC_4; return T_NO_ARG_INST;}
"shl"			{nvmparser_lval.number =  SHL; return T_NO_ARG_INST;}
"shr"			{nvmparser_lval.number =  SHR; return T_NO_ARG_INST;}
"ushr"			{nvmparser_lval.number =  USHR; return T_NO_ARG_INST;}
"rnd"			{nvmparser_lval.number =  IRND; return T_NO_ARG_INST;}
"cmp"			{nvmparser_lval.number =  CMP; return T_NO_ARG_INST;}
"mcmp"			{nvmparser_lval.number =  MCMP; return T_NO_ARG_INST;}
"jcmp.eq"		{nvmparser_lval.number =  JCMPEQ; return T_1LABEL_INST;}
"jcmp.neq"		{nvmparser_lval.number =  JCMPNEQ; return T_1LABEL_INST;}
"jcmp.g"		{nvmparser_lval.number =  JCMPG; return T_1LABEL_INST;}
"jcmp.ge"		{nvmparser_lval.number =  JCMPGE; return T_1LABEL_INST;}
"jcmp.l"		{nvmparser_lval.number =  JCMPL; return T_1LABEL_INST;}
"jcmp.le"		{nvmparser_lval.number =  JCMPLE; return T_1LABEL_INST;}
"jcmp.gts"		{nvmparser_lval.number =  JCMPG_S; return T_1LABEL_INST;}
"jcmp.ges"		{nvmparser_lval.number =  JCMPGE_S; return T_1LABEL_INST;}
"jcmp.lts"		{nvmparser_lval.number =  JCMPL_S; return T_1LABEL_INST;}
"jcmp.les"		{nvmparser_lval.number =  JCMPLE_S; return T_1LABEL_INST;}
"cmp.s"			{nvmparser_lval.number =  CMP_S; return T_1LABEL_INST;}
"rol"			{nvmparser_lval.number =  ROTL; return T_NO_ARG_INST;}
"ror"			{nvmparser_lval.number =  ROTR; return T_NO_ARG_INST;}
"push"			{nvmparser_lval.number =  PUSH; return T_1INT_ARG_INST;}
"push2"			{nvmparser_lval.number =  PUSH2; return T_2INT_ARG_INST;}
"pop"			{nvmparser_lval.number =  POP; return T_NO_ARG_INST;}
"popi"			{nvmparser_lval.number =  POP_I; return T_1BYTE_ARG_INST;}
"push_1"		{nvmparser_lval.number =  CONST_1; return T_NO_ARG_INST;}
"push_2"		{nvmparser_lval.number =  CONST_2; return T_NO_ARG_INST;}
"push_0"		{nvmparser_lval.number =  CONST_0; return T_NO_ARG_INST;}
"push__1"		{nvmparser_lval.number =  CONST__1; return T_NO_ARG_INST;}
"tstamp_s"		{nvmparser_lval.number =  TSTAMP_S; return T_NO_ARG_INST;}
"tstamp_us"		{nvmparser_lval.number =  TSTAMP_US; return T_NO_ARG_INST;}
"dup"			{nvmparser_lval.number =  DUP; return T_NO_ARG_INST;}
"swap"			{nvmparser_lval.number =  SWAP; return T_NO_ARG_INST;}
"ieswap"		{nvmparser_lval.number =  IESWAP; return T_NO_ARG_INST;}
"sleep"			{nvmparser_lval.number =  SLEEP; return T_NO_ARG_INST;}
"pbl"			{nvmparser_lval.number =  PBL; return T_NO_ARG_INST;}
"j.eq"			{nvmparser_lval.number =  JEQ; return T_1LABEL_INST;}
"j.ne"			{nvmparser_lval.number =  JNE; return T_1LABEL_INST;}
"jump"			{nvmparser_lval.number =  JUMP; return T_1_SHORT_LABEL_INST;}
"jump.w"		{nvmparser_lval.number =  JUMPW; return T_1LABEL_INST;}
"switch"		{nvmparser_lval.number =  SWITCH; return T_JMP_TBL_LKUP_INST;}
"call"			{nvmparser_lval.number =  CALL; return T_1LABEL_INST;}
"call.w"		{nvmparser_lval.number =  CALLW; return T_1LABEL_INST;}
"ret"			{nvmparser_lval.number =  RET; return T_NO_ARG_INST;}
"jfield.eq"		{nvmparser_lval.number =  JFLDEQ; return T_1LABEL_INST;}
"jfield.ne"		{nvmparser_lval.number =  JFLDNEQ; return T_1LABEL_INST;}
"jfield.lt"		{nvmparser_lval.number =  JFLDLT; return T_1LABEL_INST;}
"jfield.gt"		{nvmparser_lval.number =  JFLDGT; return T_1LABEL_INST;}
"pscan.8"		{nvmparser_lval.number =  PSCANB; return T_NO_ARG_INST;}
"pscan.16"		{nvmparser_lval.number =  PSCANW; return T_NO_ARG_INST;}
"pscan.32"		{nvmparser_lval.number =  PSCANDW; return T_NO_ARG_INST;}
"pkt.send"		{nvmparser_lval.number =  SNDPKT; return T_1_PUSH_PORT_ARG_INST;}
"pkt.senddup"		{nvmparser_lval.number =  DSNDPKT; return T_1_PUSH_PORT_ARG_INST;}
"pkt.receive"		{nvmparser_lval.number =  RCVPKT; return T_1_PULL_PORT_ARG_INST;}
"dpcopy"		{nvmparser_lval.number =  DPMCPY; return T_NO_ARG_INST;}
"pdcopy"		{nvmparser_lval.number =  PDMCPY; return T_NO_ARG_INST;}
"dscopy"		{nvmparser_lval.number =  DSMCPY; return T_NO_ARG_INST;}
"sdcopy"		{nvmparser_lval.number =  SDMCPY; return T_NO_ARG_INST;}
"spcopy"		{nvmparser_lval.number =  SPMCPY; return T_NO_ARG_INST;}
"pscopy"		{nvmparser_lval.number =  PSMCPY; return T_NO_ARG_INST;}
"ipcopy"		{nvmparser_lval.number =  IPMCPY; return T_NO_ARG_INST;}
"exbuf.create"		{nvmparser_lval.number =  CRTEXBUF; return T_NO_ARG_INST;}
"exbuf.delete"		{nvmparser_lval.number =  DELEXBUF; return T_NO_ARG_INST;}
"set.share"		{nvmparser_lval.number =  SSMSIZE; return T_1INT_ARG_INST;}
"loade"			{nvmparser_lval.number =  LOADE; return T_1INT_ARG_INST;}
"storee"		{nvmparser_lval.number =  STOREE; return T_1INT_ARG_INST;}
"nop"			{nvmparser_lval.number =  NOP; return T_NO_ARG_INST;}
"break"			{nvmparser_lval.number =  BRKPOINT; return T_NO_ARG_INST;}
"exit"			{nvmparser_lval.number =  EXIT; return T_1INT_ARG_INST;}
"info.clr"		{nvmparser_lval.number =  INFOCLR; return T_NO_ARG_INST;}
"find.bit"		{nvmparser_lval.number =  FINDBITSET; return T_NO_ARG_INST;}
"mfind.bit"		{nvmparser_lval.number =  MFINDBITSET; return T_NO_ARG_INST;}
"xfind.bit"		{nvmparser_lval.number =  XFINDBITSET; return T_1BYTE_ARG_INST;}
"xmfind.bit"		{nvmparser_lval.number =  XMFINDBITSET; return T_1BYTE_ARG_INST;}
"set.bit"		{nvmparser_lval.number =  SETBIT; return T_NO_ARG_INST;}
"clear.bit"		{nvmparser_lval.number =  CLEARBIT; return T_NO_ARG_INST;}
"flip.bit"		{nvmparser_lval.number =  FLIPBIT; return T_NO_ARG_INST;}
"test.bit"		{nvmparser_lval.number =  TESTBIT; return T_NO_ARG_INST;}
"testn.bit"		{nvmparser_lval.number =  TESTNBIT; return T_NO_ARG_INST;}
"clz"			{nvmparser_lval.number =  CLZ; return T_NO_ARG_INST;}
"hash.32"		{nvmparser_lval.number =  HASH32; return T_NO_ARG_INST;}
"hash"			{nvmparser_lval.number =  HASH; return T_1BYTE_ARG_INST;}
"chksum.add"		{nvmparser_lval.number =  CHKSUMADD; return T_NO_ARG_INST;}
"chksum.sub"		{nvmparser_lval.number =  CHKSUMSUB; return T_NO_ARG_INST;}
"chksum.calc"		{nvmparser_lval.number =  CHKSUMCALCPKT; return T_NO_ARG_INST;}
"chksum.jump"		{nvmparser_lval.number =  JUMPCHECKSUM; return T_1_SHORT_LABEL_INST;}
"crc.calc"		{nvmparser_lval.number =  CRCCALC; return T_1BYTE_ARG_INST;}
"crc.calcpkt"		{nvmparser_lval.number =  CRCCALCPKT; return T_1BYTE_ARG_INST;}
"locload"		{nvmparser_lval.number =  LOCLD; return T_1INT_ARG_INST;}
"locstore"		{nvmparser_lval.number =  LOCST; return T_1INT_ARG_INST;}
"copro.init"		{nvmparser_lval.number =  COPINIT; return T_COPRO_INIT_INST;}
"copro.in"		{nvmparser_lval.number =  COPIN; return T_2_COPRO_IO_ARG_INST;}
"copro.out"		{nvmparser_lval.number =  COPOUT; return T_2_COPRO_IO_ARG_INST;}
"copro.invoke"		{nvmparser_lval.number =  COPRUN; return T_2_COPRO_IO_ARG_INST;}
"copro.exbuf"		{nvmparser_lval.number =  COPPKTOUT; return T_2_COPRO_IO_ARG_INST;}

push_input		{nvmparser_lval.number = (nvmPORT_EXPORTER | nvmCONNECTION_PUSH); return PORT_TYPE;}
push_output		{nvmparser_lval.number = (nvmPORT_COLLECTOR | nvmCONNECTION_PUSH); return PORT_TYPE;}
pull_input		{nvmparser_lval.number = (nvmPORT_EXPORTER | nvmCONNECTION_PULL); return PORT_TYPE;}
pull_output		{nvmparser_lval.number = (nvmPORT_COLLECTOR | nvmCONNECTION_PULL); return PORT_TYPE;}
use_coprocessor		{return COPRO_DECL;}
db			return T_DB;
dw			return T_DW;
dd			return T_DD;
equ			return T_EQU;
default			return DEFAULTCASE;
\.ports			{strcpy(nvmparser_lval.id,yytext); return S_PORT;}
\.data			{strcpy(nvmparser_lval.id,yytext); return S_DATA;}
\.metadata		{strcpy(nvmparser_lval.id,yytext); return S_METADATA;}
{decnumber}		{uint32_t n;
					if (str2int(yytext, &n, 10) != 0)
						nvmparser_error("decimal number out of range");
					nvmparser_lval.number = n;
					return NUMBER;
				}

{hexnumber}		{uint32_t n;
					if (str2int(yytext, &n, 16) != 0)
						nvmparser_error("decimal number out of range");
					nvmparser_lval.number = n;
					return NUMBER;
				}
{dotquad}		{uint32_t n, t, i; char dotquad[16], *c; // size_t len;
					/* 12345678901234567890
					   255.255.255.255
					   max length: 15
					 */

					/* printf("matched text: '%s'\n", yytext); */
					// len = strlen(yytext);
					n = 0;
					strncpy(dotquad, yytext, sizeof(dotquad));
					dotquad[sizeof(dotquad)-1] = '\0';

					/* XXX: FIXME: Usage of strtok!!! */
					c = strtok(dotquad, ".");
					if(str2int(c, &n, 10) != 0 || n > 255) {
						/* printf("offending string: '%s'\n", c); */
						nvmparser_error("dotted quad notation (first pass) wrong or out of range");
					}

					/* printf("dotted quad: %u\n", n); */

					for(i = 0; i < 3 && (c = strtok(NULL, ".")) ; ++i) {
						if(str2int(c, &t, 10) != 0 || t > 255) {
							/* printf("offending string: '%s', pass: %u\n", c, i); */
							nvmparser_error("dotted quad notation wrong or out of range");
						}
						n <<= 8;
						n |= t;
						/* printf("dotted quad: %u\n", n); */
					}
					nvmparser_lval.number = n;
					return NUMBER;
				}

{colquad}		{uint32_t n, t, i; char colquad[12], *c; // size_t len;
					/* 12345678901234567890
					   00:00:00:00
					   max length: 11
					 */

					/* printf("matched text: '%s'\n", yytext); */
					// len = strlen(yytext);
					n = 0;
					strncpy(colquad, yytext, sizeof(colquad));
					colquad[sizeof(colquad)-1] = '\0';

					/* XXX: FIXME: Usage of strtok!!! */
					c = strtok(colquad, ":");
					if(str2int(c, &n, 16) != 0 || n > 255) {
						/* printf("offending string: '%s'\n", c); */
						nvmparser_error("colon quad notation (first pass) wrong or out of range");
					}

					/* printf("colon quad: %u\n", n); */

					for(i = 0; i < 3 && (c = strtok(NULL, ":")) ; ++i) {
						if(str2int(c, &t, 16) != 0 || t > 255) {
							/* printf("offending string: '%s', pass: %u\n", c, i); */
							nvmparser_error("colon quad notation wrong or out of range");
						}
						n <<= 8;
						n |= t;
						/* printf("colon quad: %u\n", n); */
					}
					nvmparser_lval.number = n;
					return NUMBER;
				}
{string}   		{
				if (yyleng - 2 > 1024 - 1)
						printf ("String too long!!!\n");
				strncpy (nvmparser_lval.id, yytext + 1, yyleng - 2);  /* Copy trimming away quotes */
				nvmparser_lval.id[yyleng - 2] = '\0';
				return (STRING);
			}


{var}			{/*printf ("LABEL: %s\n", yytext);*/ strcpy(nvmparser_lval.id,yytext); return LABEL;};
\.{var}			{strcpy(nvmparser_lval.id,yytext); return IDENTIFIER;};
{address}		{/*printf ("ADDR!\n");*/ strcpy(nvmparser_lval.id,yytext); return T_ADDR;}
\;{char}*{newline}					eline++; //remove comments
\;{char}*{newline}(\'{newline})		eline+=2; //remove comments - Ivano: this happens with the official NetPDL. In fact there is a swith in HTTP with matches the character 0xD, i.e. new line.
\(				{return('(');}
\)				{return(')');}
\*				return('*');
\/				return('/');
\+				return('+');
\-				return('-');
\:				return ':';
\,				return ',';
{newline}		eline++;
" "|\t			;
.				nvmparser_error("Invalid character:"); {printf("\t%s\n",yytext);}

%%

void netvm_lex_init(char *buf)
{
	in_buffer = nvmparser__scan_string(buf);
}

/*
 * Do any cleanup necessary after parsing.
 */
void netvm_lex_cleanup()
{
	if (in_buffer != NULL)
		nvmparser__delete_buffer(in_buffer);
	in_buffer = NULL;
}


int nvmparser_wrap() { return 1; }


int32_t str2int(const char *s, uint32_t *num, uint8_t base)
{
uint32_t n;
char *endp;

	n = strtoul(s, &endp, base);
	if ((*endp != '\0') || (errno == ERANGE))
		return -1;

	*num = n;

	return 0;

}
