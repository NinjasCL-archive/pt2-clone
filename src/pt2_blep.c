// these BLEP routines were coded by aciddose

#include <stdint.h>
#include <assert.h>
#include "pt2_blep.h"

/* Why this table is not represented as readable floating-point numbers:
** Accurate double representation in string format requires at least 14 digits and normalized
** (scientific) notation, notwithstanding compiler issues with precision or rounding error.
** Also, don't touch this table ever, just keep it exactly identical!
*/

static const uint64_t minblepdata[] =
{
	0x3FF000320C7E95A6,0x3FF00049BE220FD5,0x3FF0001B92A41ACA,0x3FEFFF4425AA9724,
	0x3FEFFDABDF6CF05C,0x3FEFFB5AF233EF1A,0x3FEFF837E2AE85F3,0x3FEFF4217B80E938,
	0x3FEFEEECEB4E0444,0x3FEFE863A8358B5F,0x3FEFE04126292670,0x3FEFD63072A0D592,
	0x3FEFC9C9CD36F56F,0x3FEFBA90594BD8C3,0x3FEFA7F008BA9F13,0x3FEF913BE2A0E0E2,
	0x3FEF75ACCB01A327,0x3FEF5460F06A4E8F,0x3FEF2C5C0389BD3C,0x3FEEFC8859BF6BCB,
	0x3FEEC3B916FD8D19,0x3FEE80AD74F0AD16,0x3FEE32153552E2C7,0x3FEDD69643CB9778,
	0x3FED6CD380FFA864,0x3FECF374A4D2961A,0x3FEC692F19B34E54,0x3FEBCCCFA695DD5C,
	0x3FEB1D44B168764A,0x3FEA59A8D8E4527F,0x3FE9814D9B10A9A3,0x3FE893C5B62135F2,
	0x3FE790EEEBF9DABD,0x3FE678FACDEE27FF,0x3FE54C763699791A,0x3FE40C4F1B1EB7A3,
	0x3FE2B9D863D4E0F3,0x3FE156CB86586B0B,0x3FDFCA8F5005B828,0x3FDCCF9C3F455DAC,
	0x3FD9C2787F20D06E,0x3FD6A984CAD0F3E5,0x3FD38BB0C452732E,0x3FD0705EC7135366,
	0x3FCABE86754E238F,0x3FC4C0801A6E9A04,0x3FBDECF490C5EA17,0x3FB2DFFACE9CE44B,
	0x3FA0EFD4449F4620,0xBF72F4A65E22806D,0xBFA3F872D761F927,0xBFB1D89F0FD31F7C,
	0xBFB8B1EA652EC270,0xBFBE79B82A37C92D,0xBFC1931B697E685E,0xBFC359383D4C8ADA,
	0xBFC48F3BFF81B06B,0xBFC537BBA8D6B15C,0xBFC557CEF2168326,0xBFC4F6F781B3347A,
	0xBFC41EF872F0E009,0xBFC2DB9F119D54D3,0xBFC13A7E196CB44F,0xBFBE953A67843504,
	0xBFBA383D9C597E74,0xBFB57FBD67AD55D6,0xBFB08E18234E5CB3,0xBFA70B06D699FFD1,
	0xBF9A1CFB65370184,0xBF7B2CEB901D2067,0x3F86D5DE2C267C78,0x3F9C1D9EF73F384D,
	0x3FA579C530950503,0x3FABD1E5FFF9B1D0,0x3FB07DCDC3A4FB5B,0x3FB2724A856EEC1B,
	0x3FB3C1F7199FC822,0x3FB46D0979F5043B,0x3FB47831387E0110,0x3FB3EC4A58A3D527,
	0x3FB2D5F45F8889B3,0x3FB145113E25B749,0x3FAE9860D18779BC,0x3FA9FFD5F5AB96EA,
	0x3FA4EC6C4F47777E,0x3F9F16C5B2604C3A,0x3F9413D801124DB7,0x3F824F668CBB5BDF,
	0xBF55B3FA2EE30D66,0xBF86541863B38183,0xBF94031BBBD551DE,0xBF9BAFC27DC5E769,
	0xBFA102B3683C57EC,0xBFA3731E608CC6E4,0xBFA520C9F5B5DEBD,0xBFA609DC89BE6ECE,
	0xBFA632B83BC5F52F,0xBFA5A58885841AD4,0xBFA471A5D2FF02F3,0xBFA2AAD5CD0377C7,
	0xBFA0686FFE4B9B05,0xBF9B88DE413ACB69,0xBF95B4EF6D93F1C5,0xBF8F1B72860B27FA,
	0xBF8296A865CDF612,0xBF691BEEDABE928B,0x3F65C04E6AF9D4F1,0x3F8035D8FFCDB0F8,
	0x3F89BED23C431BE3,0x3F90E737811A1D21,0x3F941C2040BD7CB1,0x3F967046EC629A09,
	0x3F97DE27ECE9ED89,0x3F98684DE31E7040,0x3F9818C4B07718FA,0x3F97005261F91F60,
	0x3F95357FDD157646,0x3F92D37C696C572A,0x3F8FF1CFF2BEECB5,0x3F898D20C7A72AC4,
	0x3F82BC5B3B0AE2DF,0x3F7784A1B8E9E667,0x3F637BB14081726B,0xBF4B2DACA70C60A9,
	0xBF6EFB00AD083727,0xBF7A313758DC6AE9,0xBF819D6A99164BE0,0xBF8533F57533403B,
	0xBF87CD120DB5D340,0xBF89638549CD25DE,0xBF89FB8B8D37B1BB,0xBF89A21163F9204E,
	0xBF886BA8931297D4,0xBF8673477783D71E,0xBF83D8E1CB165DB8,0xBF80BFEA7216142A,
	0xBF7A9B9BC2E40EBF,0xBF7350E806435A7E,0xBF67D35D3734AB5E,0xBF52ADE8FEAB8DB9,
	0x3F415669446478E4,0x3F60C56A092AFB48,0x3F6B9F4334A4561F,0x3F724FB908FD87AA,
	0x3F75CC56DFE382EA,0x3F783A0C23969A7B,0x3F799833C40C3B82,0x3F79F02721981BF3,
	0x3F7954212AB35261,0x3F77DDE0C5FC15C9,0x3F75AD1C98FE0777,0x3F72E5DACC0849F2,
	0x3F6F5D7E69DFDE1B,0x3F685EC2CA09E1FD,0x3F611D750E54DF3A,0x3F53C6E392A46D17,
	0x3F37A046885F3365,0xBF3BB034D2EE45C2,0xBF5254267B04B482,0xBF5C0516F9CECDC6,
	0xBF61E5736853564D,0xBF64C464B9CC47AB,0xBF669C1AEF258F56,0xBF67739985DD0E60,
	0xBF675AFD6446395B,0xBF666A0C909B4F78,0xBF64BE9879A7A07B,0xBF627AC74B119DBD,
	0xBF5F86B04069DC9B,0xBF597BE8F754AF5E,0xBF531F3EAAE9A1B1,0xBF496D3DE6AD7EA3,
	0xBF3A05FFDE4670CF,0xBF06DF95C93A85CA,0x3F31EE2B2C6547AC,0x3F41E694A378C129,
	0x3F4930BF840E23C9,0x3F4EBB5D05A0D47D,0x3F51404DA0539855,0x3F524698F56B3F33,
	0x3F527EF85309E28F,0x3F51FE70FE2513DE,0x3F50DF1642009B74,0x3F4E7CDA93517CAE,
	0x3F4A77AE24F9A533,0x3F45EE226AA69E10,0x3F411DB747374F52,0x3F387F39D229D97F,
	0x3F2E1B3D39AF5F8B,0x3F18F557BB082715,0xBEFAC04896E68DDB,0xBF20F5BC77DF558A,
	0xBF2C1B6DF3EE94A4,0xBF3254602A816876,0xBF354E90F6EAC26B,0xBF3709F2E5AF1624,
	0xBF379FCCB331CE8E,0xBF37327192ADDAD3,0xBF35EA998A894237,0xBF33F4C4977B3489,
	0xBF317EC5F68E887B,0xBF2D6B1F793EB773,0xBF2786A226B076D9,0xBF219BE6CEC2CA36,
	0xBF17D7F36D2A3A18,0xBF0AAEC5BBAB42AB,0xBEF01818DC224040,0x3EEF2F6E21093846,
	0x3F049D6E0060B71F,0x3F0E598CCAFABEFD,0x3F128BC14BE97261,0x3F148703BC70EF6A,
	0x3F1545E1579CAA25,0x3F14F7DDF5F8D766,0x3F13D10FF9A1BE0C,0x3F1206D5738ECE3A,
	0x3F0F99F6BF17C5D4,0x3F0AA6D7EA524E96,0x3F0588DDF740E1F4,0x3F0086FB6FEA9839,
	0x3EF7B28F6D6F5EED,0x3EEEA300DCBAF74A,0x3EE03F904789777C,0x3EC1BFEB320501ED,
	0xBEC310D8E585A031,0xBED6F55ECA7E151F,0xBEDFDAA5DACDD0B7,0xBEE26944F3CF6E90,
	0xBEE346894453BD1F,0xBEE2E099305CD5A8,0xBEE190385A7EA8B2,0xBEDF4D5FA2FB6BA2,
	0xBEDAD4F371257BA0,0xBED62A9CDEB0AB32,0xBED1A6DF97B88316,0xBECB100096894E58,
	0xBEC3E8A76257D275,0xBEBBF6C29A5150C9,0xBEB296292998088E,0xBEA70A10498F0E5E,
	0xBE99E52D02F887A1,0xBE88C17F4066D432,0xBE702A716CFF56CA,0x3E409F820F781F78,
	0x3E643EA99B770FE7,0x3E67DE40CDE0A550,0x3E64F4D534A2335C,0x3E5F194536BDDF7A,
	0x3E5425CEBE1FA40A,0x3E46D7B7CC631E73,0x3E364746B6582E54,0x3E21FC07B13031DE,
	0x3E064C3D91CF7665,0x3DE224F901A0AFC7,0x3DA97D57859C74A4,0x0000000000000000,

	// extra padding needed for interpolation
	0x0000000000000000
};

const double *get_minblep_table(void) { return (const double *)minblepdata; }

#define LERP(x, y, z) ((x) + ((y) - (x)) * (z))

void blepAdd(blep_t *b, double dOffset, double dAmplitude)
{
	assert(dOffset >= 0.0 && dOffset < 1.0);

	double f = dOffset * BLEP_SP;

	int32_t i = (int32_t)f; // get integer part of f
	const double *dBlepSrc = get_minblep_table() + i;
	f -= i; // remove integer part from f

	i = b->index;
	for (int32_t n = 0; n < BLEP_NS; n++)
	{
		b->dBuffer[i] += dAmplitude * LERP(dBlepSrc[0], dBlepSrc[1], f);
		dBlepSrc += BLEP_SP;

		i = (i + 1) & BLEP_RNS;
	}

	b->samplesLeft = BLEP_NS;
}

/* 8bitbubsy: simplified, faster version of blepAdd for blep'ing voice volume.
** Result is identical! (confirmed with binary comparison w/ MOD2WAV)
*/
void blepVolAdd(blep_t *b, double dAmplitude)
{
	const double *dBlepSrc = get_minblep_table();

	int32_t i = b->index;
	for (int32_t n = 0; n < BLEP_NS; n++)
	{
		b->dBuffer[i] += dAmplitude * (*dBlepSrc);
		dBlepSrc += BLEP_SP;

		i = (i + 1) & BLEP_RNS;
	}

	b->samplesLeft = BLEP_NS;
}

double blepRun(blep_t *b, double dInput)
{
	double dBlepOutput = dInput + b->dBuffer[b->index];
	b->dBuffer[b->index] = 0.0;

	b->index = (b->index + 1) & BLEP_RNS;

	b->samplesLeft--;
	return dBlepOutput;
}
