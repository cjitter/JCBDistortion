#include "JCBDistortion.h"

namespace JCBDistortion {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	DCBlock __m_dcblock_489;
	DCBlock __m_dcblock_493;
	DCBlock __m_dcblock_490;
	DCBlock __m_dcblock_494;
	DCBlock __m_dcblock_471;
	DCBlock __m_dcblock_472;
	int __exception;
	int vectorsize;
	t_sample m_R_ap_low_lp1_y_233;
	t_sample m_R_ap_low_lp2_x_232;
	t_sample m_R_ap_low_lp2_y_231;
	t_sample m_R_ap_low_lp1_y_234;
	t_sample m_R_u2_y_237;
	t_sample m_R_u2_y_236;
	t_sample m_R_ap_low_lp1_x_235;
	t_sample m_R_ap_low_lp2_y_230;
	t_sample m_R_ap_low_hp1_x_229;
	t_sample m_R_ap_low_hp2_y_225;
	t_sample m_R_ap_low_hp1_y_227;
	t_sample m_R_ap1_lp1_y_222;
	t_sample m_R_ap1_lp1_y_221;
	t_sample m_R_ap1_lp2_x_220;
	t_sample m_R_ap_low_hp1_y_228;
	t_sample m_R_ap1_lp1_x_223;
	t_sample m_R_u2_x_238;
	t_sample m_R_ap_low_hp2_y_224;
	t_sample m_R_ap_low_hp2_x_226;
	t_sample m_R_u1_y_239;
	t_sample m_R_m2_y_242;
	t_sample m_R_u1_x_241;
	t_sample m_R_l2_y_254;
	t_sample m_R_h1_x_253;
	t_sample m_R_h1_y_252;
	t_sample m_R_h1_y_251;
	t_sample m_R_l2_y_255;
	t_sample m_R_l1_y_257;
	t_sample m_R_l2_x_256;
	t_sample m_R_l1_y_258;
	t_sample m_R_u1_y_240;
	t_sample m_R_h2_x_250;
	t_sample m_R_h2_y_248;
	t_sample m_R_m2_y_243;
	t_sample m_R_ap1_lp2_y_219;
	t_sample m_R_h2_y_249;
	t_sample m_R_m2_x_244;
	t_sample m_R_m1_y_246;
	t_sample m_R_m1_y_245;
	t_sample m_R_m1_x_247;
	t_sample m_R_ap1_lp2_y_218;
	t_sample m_R_ap1_hp2_x_214;
	t_sample m_R_ap1_hp1_y_216;
	t_sample m_h1_x_190;
	t_sample m_h1_y_189;
	t_sample m_h1_y_188;
	t_sample m_h2_x_187;
	t_sample m_h1_x_191;
	t_sample m_l2_y_193;
	t_sample m_l2_y_192;
	t_sample m_l2_x_194;
	t_sample m_l2_x_195;
	t_sample m_h2_x_186;
	t_sample m_h2_y_184;
	t_sample m_m2_x_179;
	t_sample m_m2_x_178;
	t_sample m_m2_y_177;
	t_sample m_h2_y_185;
	t_sample m_m1_y_180;
	t_sample m_m1_x_182;
	t_sample m_m1_y_181;
	t_sample m_m1_x_183;
	t_sample m_R_ap1_hp1_x_217;
	t_sample m_l1_y_196;
	t_sample m_l1_x_198;
	t_sample m_R_ap2_lp1_x_211;
	t_sample m_R_ap2_lp1_y_210;
	t_sample m_R_ap2_lp1_y_209;
	t_sample m_R_ap2_lp2_x_208;
	t_sample m_R_ap1_hp2_y_212;
	t_sample m_R_l1_x_259;
	t_sample m_R_ap1_hp2_y_213;
	t_sample m_R_ap1_hp1_y_215;
	t_sample m_l1_y_197;
	t_sample m_R_ap2_lp2_y_207;
	t_sample m_R_ap2_hp1_x_205;
	t_sample m_R_ap2_hp2_y_200;
	t_sample m_l1_x_199;
	t_sample m_R_ap2_lp2_y_206;
	t_sample m_R_ap2_hp2_y_201;
	t_sample m_R_ap2_hp1_y_203;
	t_sample m_R_ap2_hp2_x_202;
	t_sample m_R_ap2_hp1_y_204;
	t_sample m_L_ap2_hp2_y_260;
	t_sample m_L_ap2_hp1_y_263;
	t_sample m_L_ap2_hp2_x_262;
	t_sample m_L_l1_y_318;
	t_sample m_L_l1_y_317;
	t_sample m_L_l2_x_316;
	t_sample m_L_l2_y_315;
	t_sample m_L_l1_x_319;
	t_sample m_r_TONEFREQ_321;
	t_sample m_t_TONEQ_320;
	t_sample m_q_TONEON_322;
	t_sample m_p_SAFELIMITON_323;
	t_sample m_L_l2_y_314;
	t_sample m_L_h1_y_312;
	t_sample m_L_m1_x_307;
	t_sample m_L_m1_y_306;
	t_sample m_L_m1_y_305;
	t_sample m_L_h1_x_313;
	t_sample m_L_h2_y_308;
	t_sample m_L_h2_x_310;
	t_sample m_L_h2_y_309;
	t_sample m_L_h1_y_311;
	t_sample m_L_m2_x_304;
	t_sample m_p_BANDSOLO_324;
	t_sample m_p_TILTPOS_326;
	t_sample m_e_CEILING_339;
	t_sample m_f_BYPASS_338;
	t_sample m_g_BITS_337;
	t_sample m_h_BITSON_336;
	t_sample m_d_MODE_340;
	t_sample m_b_DRIVE_342;
	t_sample m_c_DC_341;
	t_sample m_a_DRYWET_343;
	t_sample m_p_DISTON_325;
	t_sample m_i_TILT_335;
	t_sample m_k_LPF_333;
	t_sample m_n_DOWNSAMPLEON_328;
	t_sample m_o_BAND_327;
	t_sample m_j_HPF_334;
	t_sample m_m_DOWNSAMPLE_329;
	t_sample m_k_INPUT_331;
	t_sample m_l_OUTPUT_330;
	t_sample m_l_SC_332;
	t_sample m_L_ap2_hp2_y_261;
	t_sample m_L_m2_y_303;
	t_sample m_L_u1_x_301;
	t_sample m_L_ap1_hp1_y_275;
	t_sample m_L_ap1_hp2_x_274;
	t_sample m_L_ap1_hp2_y_273;
	t_sample m_L_ap1_hp2_y_272;
	t_sample m_L_ap1_hp1_y_276;
	t_sample m_L_ap1_lp2_y_278;
	t_sample m_L_ap1_hp1_x_277;
	t_sample m_L_ap1_lp2_y_279;
	t_sample m_L_ap1_lp2_x_280;
	t_sample m_L_ap2_lp1_x_271;
	t_sample m_L_ap2_lp1_y_269;
	t_sample m_L_ap2_hp1_y_264;
	t_sample m_m2_y_176;
	t_sample m_L_ap2_lp1_y_270;
	t_sample m_L_ap2_hp1_x_265;
	t_sample m_L_ap2_lp2_y_267;
	t_sample m_L_ap2_lp2_y_266;
	t_sample m_L_ap2_lp2_x_268;
	t_sample m_L_m2_y_302;
	t_sample m_L_ap1_lp1_y_281;
	t_sample m_L_ap1_lp1_x_283;
	t_sample m_L_u2_y_296;
	t_sample m_L_ap_low_lp1_x_295;
	t_sample m_L_ap_low_lp1_y_294;
	t_sample m_L_ap_low_lp1_y_293;
	t_sample m_L_u2_y_297;
	t_sample m_L_u1_y_299;
	t_sample m_L_u2_x_298;
	t_sample m_L_u1_y_300;
	t_sample m_L_ap1_lp1_y_282;
	t_sample m_L_ap_low_lp2_x_292;
	t_sample m_L_ap_low_lp2_y_290;
	t_sample m_L_ap_low_hp2_y_285;
	t_sample m_L_ap_low_hp2_y_284;
	t_sample m_L_ap_low_lp2_y_291;
	t_sample m_L_ap_low_hp2_x_286;
	t_sample m_L_ap_low_hp1_y_288;
	t_sample m_L_ap_low_hp1_y_287;
	t_sample m_L_ap_low_hp1_x_289;
	t_sample m_u1_x_175;
	t_sample m_u1_x_174;
	t_sample m_u1_y_173;
	t_sample m_R_h1_x_57;
	t_sample m_L_h2_x_56;
	t_sample m_R_h2_x_55;
	t_sample m_L_m1_x_54;
	t_sample m_L_h1_x_58;
	t_sample m_L_l2_x_60;
	t_sample m_R_l2_x_59;
	t_sample m_L_l1_x_62;
	t_sample m_R_l1_x_61;
	t_sample m_postTiltHsR_63;
	t_sample m_R_m1_x_53;
	t_sample m_R_m2_x_51;
	t_sample m_L_ap_low_lp1_x_46;
	t_sample m_R_ap_low_lp1_x_45;
	t_sample m_L_ap_low_lp2_x_44;
	t_sample m_L_m2_x_52;
	t_sample m_R_u2_x_47;
	t_sample m_R_u1_x_49;
	t_sample m_L_u2_x_48;
	t_sample m_L_u1_x_50;
	t_sample m_R_ap_low_lp2_x_43;
	t_sample m_postTiltHsR_64;
	t_sample m_postTiltHsR_66;
	t_sample m_tiltHsR_80;
	t_sample m_hTiltPos_79;
	t_sample m_postTiltLsL_78;
	t_sample m_postTiltLsL_77;
	t_sample m_tiltHsR_81;
	t_sample m_tiltHsR_83;
	t_sample m_tiltHsR_82;
	t_sample m_tiltHsL_84;
	t_sample m_postTiltHsR_65;
	t_sample m_postTiltLsL_76;
	t_sample m_postTiltLsR_74;
	t_sample m_postTiltHsL_69;
	t_sample m_postTiltHsL_68;
	t_sample m_postTiltHsL_67;
	t_sample m_postTiltLsL_75;
	t_sample m_postTiltHsL_70;
	t_sample m_postTiltLsR_72;
	t_sample m_postTiltLsR_71;
	t_sample m_postTiltLsR_73;
	t_sample m_tiltHsL_85;
	t_sample m_L_ap_low_hp1_x_42;
	t_sample m_L_ap_low_hp2_x_40;
	t_sample m_toneR_x_13;
	t_sample m_toneR_x_12;
	t_sample m_toneR_y_11;
	t_sample m_toneR_y_10;
	t_sample m_toneL_y_14;
	t_sample m_toneL_x_16;
	t_sample m_toneL_y_15;
	t_sample m_toneL_x_17;
	t_sample m_hToneFreq_18;
	t_sample m_hToneQ_9;
	t_sample m_toneApL_x_7;
	t_sample m_toneApR_y_2;
	t_sample m_toneApR_y_1;
	t_sample samplerate;
	t_sample m_toneApL_x_8;
	t_sample m_toneApR_x_3;
	t_sample m_toneApL_y_5;
	t_sample m_toneApR_x_4;
	t_sample m_toneApL_y_6;
	t_sample m_R_ap_low_hp1_x_41;
	t_sample m_hToneOn_19;
	t_sample m_hBandSolo_21;
	t_sample m_R_ap1_lp2_x_35;
	t_sample m_L_ap1_hp1_x_34;
	t_sample m_R_ap1_hp1_x_33;
	t_sample m_L_ap1_hp2_x_32;
	t_sample m_L_ap1_lp2_x_36;
	t_sample m_L_ap1_lp1_x_38;
	t_sample m_R_ap1_lp1_x_37;
	t_sample m_R_ap_low_hp2_x_39;
	t_sample m_hSafeLimitOn_20;
	t_sample m_R_ap1_hp2_x_31;
	t_sample m_R_ap2_lp1_x_29;
	t_sample m_L_ap2_hp2_x_24;
	t_sample m_R_ap2_hp2_x_23;
	t_sample m_hDistOn_22;
	t_sample m_L_ap2_lp1_x_30;
	t_sample m_R_ap2_hp1_x_25;
	t_sample m_R_ap2_lp2_x_27;
	t_sample m_L_ap2_hp1_x_26;
	t_sample m_L_ap2_lp2_x_28;
	t_sample __m_latch_497;
	t_sample m_tiltHsL_86;
	t_sample m_tiltLsR_88;
	t_sample m_ap1_lp2_x_146;
	t_sample m_ap1_lp2_y_145;
	t_sample m_ap1_lp2_y_144;
	t_sample m_ap1_hp1_x_143;
	t_sample m_ap1_lp2_x_147;
	t_sample m_ap1_lp1_y_149;
	t_sample m_ap1_lp1_y_148;
	t_sample m_ap1_lp1_x_150;
	t_sample m_ap1_lp1_x_151;
	t_sample m_ap1_hp1_x_142;
	t_sample m_ap1_hp1_y_140;
	t_sample m_ap2_lp1_x_135;
	t_sample m_ap2_lp1_x_134;
	t_sample m_ap2_lp1_y_133;
	t_sample m_ap1_hp1_y_141;
	t_sample m_ap1_hp2_y_136;
	t_sample m_ap1_hp2_x_138;
	t_sample m_ap1_hp2_y_137;
	t_sample m_ap1_hp2_x_139;
	t_sample m_ap2_lp1_y_132;
	t_sample m_ap_low_hp2_y_152;
	t_sample m_ap_low_hp2_x_154;
	t_sample m_u2_y_168;
	t_sample m_ap_low_lp1_x_167;
	t_sample m_ap_low_lp1_x_166;
	t_sample m_ap_low_lp1_y_165;
	t_sample m_u2_y_169;
	t_sample m_u2_x_171;
	t_sample m_u2_x_170;
	t_sample m_u1_y_172;
	t_sample m_ap_low_hp2_y_153;
	t_sample m_ap_low_lp1_y_164;
	t_sample m_ap_low_lp2_x_162;
	t_sample m_ap_low_hp1_y_157;
	t_sample m_ap_low_hp1_y_156;
	t_sample m_ap_low_hp2_x_155;
	t_sample m_ap_low_lp2_x_163;
	t_sample m_ap_low_hp1_x_158;
	t_sample m_ap_low_lp2_y_160;
	t_sample m_ap_low_hp1_x_159;
	t_sample m_ap_low_lp2_y_161;
	t_sample m_tiltHsL_87;
	t_sample m_ap2_lp2_x_131;
	t_sample m_ap2_lp2_y_129;
	t_sample m_hpfFreqHistory_102;
	t_sample m_lpfFreqHistory_101;
	t_sample m_scEnableHistory_100;
	t_sample m_dsPhasor_99;
	t_sample m_lpfR_z_103;
	t_sample m_hpfR_z_105;
	t_sample m_lpfL_z_104;
	t_sample m_hpfL_z_106;
	t_sample m_hBypass_107;
	t_sample m_dsPhase_98;
	t_sample m_dsEnablePrev_96;
	t_sample m_tiltLsR_91;
	t_sample m_tiltLsR_90;
	t_sample m_tiltLsR_89;
	t_sample m_dsTrigPrev_97;
	t_sample m_tiltLsL_92;
	t_sample m_tiltLsL_94;
	t_sample m_tiltLsL_93;
	t_sample m_tiltLsL_95;
	t_sample m_ap2_lp2_x_130;
	t_sample m_hDownsampleOn_108;
	t_sample m_hMode_110;
	t_sample m_ap2_hp1_y_124;
	t_sample m_ap2_hp2_x_123;
	t_sample m_ap2_hp2_x_122;
	t_sample m_ap2_hp2_y_121;
	t_sample m_ap2_hp1_y_125;
	t_sample m_ap2_hp1_x_127;
	t_sample m_ap2_hp1_x_126;
	t_sample m_ap2_lp2_y_128;
	t_sample m_hDownsample_109;
	t_sample m_ap2_hp2_y_120;
	t_sample m_hDrive_118;
	t_sample m_hTilt_113;
	t_sample m_hInput_112;
	t_sample m_hOutput_111;
	t_sample m_hBand_119;
	t_sample m_hBitson_114;
	t_sample m_hDrywet_116;
	t_sample m_hBits_115;
	t_sample m_hDc_117;
	t_sample __m_latch_498;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_toneApR_y_1 = ((int)0);
		m_toneApR_y_2 = ((int)0);
		m_toneApR_x_3 = ((int)0);
		m_toneApR_x_4 = ((int)0);
		m_toneApL_y_5 = ((int)0);
		m_toneApL_y_6 = ((int)0);
		m_toneApL_x_7 = ((int)0);
		m_toneApL_x_8 = ((int)0);
		m_hToneQ_9 = ((t_sample)0.70710678118655);
		m_toneR_y_10 = ((int)0);
		m_toneR_y_11 = ((int)0);
		m_toneR_x_12 = ((int)0);
		m_toneR_x_13 = ((int)0);
		m_toneL_y_14 = ((int)0);
		m_toneL_y_15 = ((int)0);
		m_toneL_x_16 = ((int)0);
		m_toneL_x_17 = ((int)0);
		m_hToneFreq_18 = ((int)12000);
		m_hToneOn_19 = ((int)0);
		m_hSafeLimitOn_20 = ((int)0);
		m_hBandSolo_21 = ((int)0);
		m_hDistOn_22 = ((int)1);
		m_R_ap2_hp2_x_23 = ((int)0);
		m_L_ap2_hp2_x_24 = ((int)0);
		m_R_ap2_hp1_x_25 = ((int)0);
		m_L_ap2_hp1_x_26 = ((int)0);
		m_R_ap2_lp2_x_27 = ((int)0);
		m_L_ap2_lp2_x_28 = ((int)0);
		m_R_ap2_lp1_x_29 = ((int)0);
		m_L_ap2_lp1_x_30 = ((int)0);
		m_R_ap1_hp2_x_31 = ((int)0);
		m_L_ap1_hp2_x_32 = ((int)0);
		m_R_ap1_hp1_x_33 = ((int)0);
		m_L_ap1_hp1_x_34 = ((int)0);
		m_R_ap1_lp2_x_35 = ((int)0);
		m_L_ap1_lp2_x_36 = ((int)0);
		m_R_ap1_lp1_x_37 = ((int)0);
		m_L_ap1_lp1_x_38 = ((int)0);
		m_R_ap_low_hp2_x_39 = ((int)0);
		m_L_ap_low_hp2_x_40 = ((int)0);
		m_R_ap_low_hp1_x_41 = ((int)0);
		m_L_ap_low_hp1_x_42 = ((int)0);
		m_R_ap_low_lp2_x_43 = ((int)0);
		m_L_ap_low_lp2_x_44 = ((int)0);
		m_R_ap_low_lp1_x_45 = ((int)0);
		m_L_ap_low_lp1_x_46 = ((int)0);
		m_R_u2_x_47 = ((int)0);
		m_L_u2_x_48 = ((int)0);
		m_R_u1_x_49 = ((int)0);
		m_L_u1_x_50 = ((int)0);
		m_R_m2_x_51 = ((int)0);
		m_L_m2_x_52 = ((int)0);
		m_R_m1_x_53 = ((int)0);
		m_L_m1_x_54 = ((int)0);
		m_R_h2_x_55 = ((int)0);
		m_L_h2_x_56 = ((int)0);
		m_R_h1_x_57 = ((int)0);
		m_L_h1_x_58 = ((int)0);
		m_R_l2_x_59 = ((int)0);
		m_L_l2_x_60 = ((int)0);
		m_R_l1_x_61 = ((int)0);
		m_L_l1_x_62 = ((int)0);
		m_postTiltHsR_63 = ((int)0);
		m_postTiltHsR_64 = ((int)0);
		m_postTiltHsR_65 = ((int)0);
		m_postTiltHsR_66 = ((int)0);
		m_postTiltHsL_67 = ((int)0);
		m_postTiltHsL_68 = ((int)0);
		m_postTiltHsL_69 = ((int)0);
		m_postTiltHsL_70 = ((int)0);
		m_postTiltLsR_71 = ((int)0);
		m_postTiltLsR_72 = ((int)0);
		m_postTiltLsR_73 = ((int)0);
		m_postTiltLsR_74 = ((int)0);
		m_postTiltLsL_75 = ((int)0);
		m_postTiltLsL_76 = ((int)0);
		m_postTiltLsL_77 = ((int)0);
		m_postTiltLsL_78 = ((int)0);
		m_hTiltPos_79 = ((int)0);
		m_tiltHsR_80 = ((int)0);
		m_tiltHsR_81 = ((int)0);
		m_tiltHsR_82 = ((int)0);
		m_tiltHsR_83 = ((int)0);
		m_tiltHsL_84 = ((int)0);
		m_tiltHsL_85 = ((int)0);
		m_tiltHsL_86 = ((int)0);
		m_tiltHsL_87 = ((int)0);
		m_tiltLsR_88 = ((int)0);
		m_tiltLsR_89 = ((int)0);
		m_tiltLsR_90 = ((int)0);
		m_tiltLsR_91 = ((int)0);
		m_tiltLsL_92 = ((int)0);
		m_tiltLsL_93 = ((int)0);
		m_tiltLsL_94 = ((int)0);
		m_tiltLsL_95 = ((int)0);
		m_dsEnablePrev_96 = ((int)0);
		m_dsTrigPrev_97 = ((int)0);
		m_dsPhase_98 = ((int)0);
		m_dsPhasor_99 = ((int)0);
		m_scEnableHistory_100 = ((int)0);
		m_lpfFreqHistory_101 = ((int)0);
		m_hpfFreqHistory_102 = ((int)0);
		m_lpfR_z_103 = ((int)0);
		m_lpfL_z_104 = ((int)0);
		m_hpfR_z_105 = ((int)0);
		m_hpfL_z_106 = ((int)0);
		m_hBypass_107 = ((int)0);
		m_hDownsampleOn_108 = ((int)0);
		m_hDownsample_109 = ((int)0);
		m_hMode_110 = ((int)0);
		m_hOutput_111 = ((int)0);
		m_hInput_112 = ((int)0);
		m_hTilt_113 = ((int)0);
		m_hBitson_114 = ((int)0);
		m_hBits_115 = ((int)0);
		m_hDrywet_116 = ((int)0);
		m_hDc_117 = ((int)0);
		m_hDrive_118 = ((int)0);
		m_hBand_119 = ((int)1);
		m_ap2_hp2_y_120 = ((int)0);
		m_ap2_hp2_y_121 = ((int)0);
		m_ap2_hp2_x_122 = ((int)0);
		m_ap2_hp2_x_123 = ((int)0);
		m_ap2_hp1_y_124 = ((int)0);
		m_ap2_hp1_y_125 = ((int)0);
		m_ap2_hp1_x_126 = ((int)0);
		m_ap2_hp1_x_127 = ((int)0);
		m_ap2_lp2_y_128 = ((int)0);
		m_ap2_lp2_y_129 = ((int)0);
		m_ap2_lp2_x_130 = ((int)0);
		m_ap2_lp2_x_131 = ((int)0);
		m_ap2_lp1_y_132 = ((int)0);
		m_ap2_lp1_y_133 = ((int)0);
		m_ap2_lp1_x_134 = ((int)0);
		m_ap2_lp1_x_135 = ((int)0);
		m_ap1_hp2_y_136 = ((int)0);
		m_ap1_hp2_y_137 = ((int)0);
		m_ap1_hp2_x_138 = ((int)0);
		m_ap1_hp2_x_139 = ((int)0);
		m_ap1_hp1_y_140 = ((int)0);
		m_ap1_hp1_y_141 = ((int)0);
		m_ap1_hp1_x_142 = ((int)0);
		m_ap1_hp1_x_143 = ((int)0);
		m_ap1_lp2_y_144 = ((int)0);
		m_ap1_lp2_y_145 = ((int)0);
		m_ap1_lp2_x_146 = ((int)0);
		m_ap1_lp2_x_147 = ((int)0);
		m_ap1_lp1_y_148 = ((int)0);
		m_ap1_lp1_y_149 = ((int)0);
		m_ap1_lp1_x_150 = ((int)0);
		m_ap1_lp1_x_151 = ((int)0);
		m_ap_low_hp2_y_152 = ((int)0);
		m_ap_low_hp2_y_153 = ((int)0);
		m_ap_low_hp2_x_154 = ((int)0);
		m_ap_low_hp2_x_155 = ((int)0);
		m_ap_low_hp1_y_156 = ((int)0);
		m_ap_low_hp1_y_157 = ((int)0);
		m_ap_low_hp1_x_158 = ((int)0);
		m_ap_low_hp1_x_159 = ((int)0);
		m_ap_low_lp2_y_160 = ((int)0);
		m_ap_low_lp2_y_161 = ((int)0);
		m_ap_low_lp2_x_162 = ((int)0);
		m_ap_low_lp2_x_163 = ((int)0);
		m_ap_low_lp1_y_164 = ((int)0);
		m_ap_low_lp1_y_165 = ((int)0);
		m_ap_low_lp1_x_166 = ((int)0);
		m_ap_low_lp1_x_167 = ((int)0);
		m_u2_y_168 = ((int)0);
		m_u2_y_169 = ((int)0);
		m_u2_x_170 = ((int)0);
		m_u2_x_171 = ((int)0);
		m_u1_y_172 = ((int)0);
		m_u1_y_173 = ((int)0);
		m_u1_x_174 = ((int)0);
		m_u1_x_175 = ((int)0);
		m_m2_y_176 = ((int)0);
		m_m2_y_177 = ((int)0);
		m_m2_x_178 = ((int)0);
		m_m2_x_179 = ((int)0);
		m_m1_y_180 = ((int)0);
		m_m1_y_181 = ((int)0);
		m_m1_x_182 = ((int)0);
		m_m1_x_183 = ((int)0);
		m_h2_y_184 = ((int)0);
		m_h2_y_185 = ((int)0);
		m_h2_x_186 = ((int)0);
		m_h2_x_187 = ((int)0);
		m_h1_y_188 = ((int)0);
		m_h1_y_189 = ((int)0);
		m_h1_x_190 = ((int)0);
		m_h1_x_191 = ((int)0);
		m_l2_y_192 = ((int)0);
		m_l2_y_193 = ((int)0);
		m_l2_x_194 = ((int)0);
		m_l2_x_195 = ((int)0);
		m_l1_y_196 = ((int)0);
		m_l1_y_197 = ((int)0);
		m_l1_x_198 = ((int)0);
		m_l1_x_199 = ((int)0);
		m_R_ap2_hp2_y_200 = ((int)0);
		m_R_ap2_hp2_y_201 = ((int)0);
		m_R_ap2_hp2_x_202 = ((int)0);
		m_R_ap2_hp1_y_203 = ((int)0);
		m_R_ap2_hp1_y_204 = ((int)0);
		m_R_ap2_hp1_x_205 = ((int)0);
		m_R_ap2_lp2_y_206 = ((int)0);
		m_R_ap2_lp2_y_207 = ((int)0);
		m_R_ap2_lp2_x_208 = ((int)0);
		m_R_ap2_lp1_y_209 = ((int)0);
		m_R_ap2_lp1_y_210 = ((int)0);
		m_R_ap2_lp1_x_211 = ((int)0);
		m_R_ap1_hp2_y_212 = ((int)0);
		m_R_ap1_hp2_y_213 = ((int)0);
		m_R_ap1_hp2_x_214 = ((int)0);
		m_R_ap1_hp1_y_215 = ((int)0);
		m_R_ap1_hp1_y_216 = ((int)0);
		m_R_ap1_hp1_x_217 = ((int)0);
		m_R_ap1_lp2_y_218 = ((int)0);
		m_R_ap1_lp2_y_219 = ((int)0);
		m_R_ap1_lp2_x_220 = ((int)0);
		m_R_ap1_lp1_y_221 = ((int)0);
		m_R_ap1_lp1_y_222 = ((int)0);
		m_R_ap1_lp1_x_223 = ((int)0);
		m_R_ap_low_hp2_y_224 = ((int)0);
		m_R_ap_low_hp2_y_225 = ((int)0);
		m_R_ap_low_hp2_x_226 = ((int)0);
		m_R_ap_low_hp1_y_227 = ((int)0);
		m_R_ap_low_hp1_y_228 = ((int)0);
		m_R_ap_low_hp1_x_229 = ((int)0);
		m_R_ap_low_lp2_y_230 = ((int)0);
		m_R_ap_low_lp2_y_231 = ((int)0);
		m_R_ap_low_lp2_x_232 = ((int)0);
		m_R_ap_low_lp1_y_233 = ((int)0);
		m_R_ap_low_lp1_y_234 = ((int)0);
		m_R_ap_low_lp1_x_235 = ((int)0);
		m_R_u2_y_236 = ((int)0);
		m_R_u2_y_237 = ((int)0);
		m_R_u2_x_238 = ((int)0);
		m_R_u1_y_239 = ((int)0);
		m_R_u1_y_240 = ((int)0);
		m_R_u1_x_241 = ((int)0);
		m_R_m2_y_242 = ((int)0);
		m_R_m2_y_243 = ((int)0);
		m_R_m2_x_244 = ((int)0);
		m_R_m1_y_245 = ((int)0);
		m_R_m1_y_246 = ((int)0);
		m_R_m1_x_247 = ((int)0);
		m_R_h2_y_248 = ((int)0);
		m_R_h2_y_249 = ((int)0);
		m_R_h2_x_250 = ((int)0);
		m_R_h1_y_251 = ((int)0);
		m_R_h1_y_252 = ((int)0);
		m_R_h1_x_253 = ((int)0);
		m_R_l2_y_254 = ((int)0);
		m_R_l2_y_255 = ((int)0);
		m_R_l2_x_256 = ((int)0);
		m_R_l1_y_257 = ((int)0);
		m_R_l1_y_258 = ((int)0);
		m_R_l1_x_259 = ((int)0);
		m_L_ap2_hp2_y_260 = ((int)0);
		m_L_ap2_hp2_y_261 = ((int)0);
		m_L_ap2_hp2_x_262 = ((int)0);
		m_L_ap2_hp1_y_263 = ((int)0);
		m_L_ap2_hp1_y_264 = ((int)0);
		m_L_ap2_hp1_x_265 = ((int)0);
		m_L_ap2_lp2_y_266 = ((int)0);
		m_L_ap2_lp2_y_267 = ((int)0);
		m_L_ap2_lp2_x_268 = ((int)0);
		m_L_ap2_lp1_y_269 = ((int)0);
		m_L_ap2_lp1_y_270 = ((int)0);
		m_L_ap2_lp1_x_271 = ((int)0);
		m_L_ap1_hp2_y_272 = ((int)0);
		m_L_ap1_hp2_y_273 = ((int)0);
		m_L_ap1_hp2_x_274 = ((int)0);
		m_L_ap1_hp1_y_275 = ((int)0);
		m_L_ap1_hp1_y_276 = ((int)0);
		m_L_ap1_hp1_x_277 = ((int)0);
		m_L_ap1_lp2_y_278 = ((int)0);
		m_L_ap1_lp2_y_279 = ((int)0);
		m_L_ap1_lp2_x_280 = ((int)0);
		m_L_ap1_lp1_y_281 = ((int)0);
		m_L_ap1_lp1_y_282 = ((int)0);
		m_L_ap1_lp1_x_283 = ((int)0);
		m_L_ap_low_hp2_y_284 = ((int)0);
		m_L_ap_low_hp2_y_285 = ((int)0);
		m_L_ap_low_hp2_x_286 = ((int)0);
		m_L_ap_low_hp1_y_287 = ((int)0);
		m_L_ap_low_hp1_y_288 = ((int)0);
		m_L_ap_low_hp1_x_289 = ((int)0);
		m_L_ap_low_lp2_y_290 = ((int)0);
		m_L_ap_low_lp2_y_291 = ((int)0);
		m_L_ap_low_lp2_x_292 = ((int)0);
		m_L_ap_low_lp1_y_293 = ((int)0);
		m_L_ap_low_lp1_y_294 = ((int)0);
		m_L_ap_low_lp1_x_295 = ((int)0);
		m_L_u2_y_296 = ((int)0);
		m_L_u2_y_297 = ((int)0);
		m_L_u2_x_298 = ((int)0);
		m_L_u1_y_299 = ((int)0);
		m_L_u1_y_300 = ((int)0);
		m_L_u1_x_301 = ((int)0);
		m_L_m2_y_302 = ((int)0);
		m_L_m2_y_303 = ((int)0);
		m_L_m2_x_304 = ((int)0);
		m_L_m1_y_305 = ((int)0);
		m_L_m1_y_306 = ((int)0);
		m_L_m1_x_307 = ((int)0);
		m_L_h2_y_308 = ((int)0);
		m_L_h2_y_309 = ((int)0);
		m_L_h2_x_310 = ((int)0);
		m_L_h1_y_311 = ((int)0);
		m_L_h1_y_312 = ((int)0);
		m_L_h1_x_313 = ((int)0);
		m_L_l2_y_314 = ((int)0);
		m_L_l2_y_315 = ((int)0);
		m_L_l2_x_316 = ((int)0);
		m_L_l1_y_317 = ((int)0);
		m_L_l1_y_318 = ((int)0);
		m_L_l1_x_319 = ((int)0);
		m_t_TONEQ_320 = 0.70710678118655;
		m_r_TONEFREQ_321 = 20000;
		m_q_TONEON_322 = 0;
		m_p_SAFELIMITON_323 = 0;
		m_p_BANDSOLO_324 = 0;
		m_p_DISTON_325 = 1;
		m_p_TILTPOS_326 = 0;
		m_o_BAND_327 = 1;
		m_n_DOWNSAMPLEON_328 = 0;
		m_m_DOWNSAMPLE_329 = 0;
		m_l_OUTPUT_330 = 0;
		m_k_INPUT_331 = 0;
		m_l_SC_332 = 0;
		m_k_LPF_333 = 5000;
		m_j_HPF_334 = 250;
		m_i_TILT_335 = 0;
		m_h_BITSON_336 = 0;
		m_g_BITS_337 = 16;
		m_f_BYPASS_338 = 0;
		m_e_CEILING_339 = 0;
		m_d_MODE_340 = 0;
		m_c_DC_341 = 0;
		m_b_DRIVE_342 = 1;
		m_a_DRYWET_343 = 1;
		__m_dcblock_471.reset();
		__m_dcblock_472.reset();
		__m_dcblock_489.reset();
		__m_dcblock_490.reset();
		__m_dcblock_493.reset();
		__m_dcblock_494.reset();
		__m_latch_497 = 0;
		__m_latch_498 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample ceiling = dbtoa(m_e_CEILING_339);
		int L_sr = samplerate;
		t_sample minb_344 = (((t_sample)0.45) * L_sr);
		t_sample minb_346 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_349 = (((t_sample)0.45) * R_sr);
		t_sample minb_351 = (((t_sample)0.45) * R_sr);
		int L_sr_2746 = samplerate;
		t_sample minb_360 = (((t_sample)0.45) * L_sr_2746);
		t_sample minb_362 = (((t_sample)0.45) * L_sr_2746);
		int R_sr_2788 = samplerate;
		t_sample minb_365 = (((t_sample)0.45) * R_sr_2788);
		t_sample minb_367 = (((t_sample)0.45) * R_sr_2788);
		t_sample omega = safediv(((t_sample)6283.1853071796), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample cosw = cs;
		t_sample sinw = sn;
		t_sample cos2 = ((cs * cs) - (sn * sn));
		t_sample sin2 = ((((int)2) * sn) * cs);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_118 = ((m_hDrive_118 * ((t_sample)0.999)) + (m_b_DRIVE_342 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_118;
			m_hDc_117 = ((m_hDc_117 * ((t_sample)0.999)) + (m_c_DC_341 * ((t_sample)0.001)));
			t_sample dc = m_hDc_117;
			m_hDrywet_116 = ((m_hDrywet_116 * ((t_sample)0.999)) + (m_a_DRYWET_343 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_116;
			m_hBits_115 = ((m_hBits_115 * ((t_sample)0.999)) + (m_g_BITS_337 * ((t_sample)0.001)));
			t_sample bits = m_hBits_115;
			m_hBitson_114 = ((m_hBitson_114 * ((t_sample)0.999)) + (m_h_BITSON_336 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_114;
			m_hTilt_113 = ((m_hTilt_113 * ((t_sample)0.999)) + (m_i_TILT_335 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_113;
			m_hInput_112 = ((m_hInput_112 * ((t_sample)0.999)) + (m_k_INPUT_331 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_112;
			m_hOutput_111 = ((m_hOutput_111 * ((t_sample)0.999)) + (m_l_OUTPUT_330 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_111;
			m_hBand_119 = ((m_hBand_119 * ((t_sample)0.999)) + (m_o_BAND_327 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_119;
			m_hMode_110 = ((m_hMode_110 * ((t_sample)0.99)) + (m_d_MODE_340 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_110;
			m_hDownsample_109 = ((m_hDownsample_109 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_329 * ((t_sample)0.001)));
			m_hDownsampleOn_108 = ((m_hDownsampleOn_108 * ((t_sample)0.9)) + (m_n_DOWNSAMPLEON_328 * ((t_sample)0.1)));
			t_sample downsampleOn = m_hDownsampleOn_108;
			m_hBypass_107 = ((m_hBypass_107 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_338) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_107;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_102 * ((t_sample)0.999)) + (m_j_HPF_334 * ((t_sample)0.001)));
			m_hpfFreqHistory_102 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_101 * ((t_sample)0.999)) + (m_k_LPF_333 * ((t_sample)0.001)));
			m_lpfFreqHistory_101 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_100 * ((t_sample)0.999)) + (m_l_SC_332 * ((t_sample)0.001)));
			m_scEnableHistory_100 = fixdenorm(smoothScEnable);
			m_hTiltPos_79 = ((m_hTiltPos_79 * ((t_sample)0.999)) + (m_p_TILTPOS_326 * ((t_sample)0.001)));
			t_sample wPost = ((m_hTiltPos_79 <= ((int)0)) ? ((int)0) : ((m_hTiltPos_79 >= ((int)1)) ? ((int)1) : m_hTiltPos_79));
			m_hDistOn_22 = ((m_hDistOn_22 * ((t_sample)0.999)) + (m_p_DISTON_325 * ((t_sample)0.001)));
			t_sample wDist = ((m_hDistOn_22 <= ((int)0)) ? ((int)0) : ((m_hDistOn_22 >= ((int)1)) ? ((int)1) : m_hDistOn_22));
			m_hBandSolo_21 = ((m_hBandSolo_21 * ((t_sample)0.999)) + (m_p_BANDSOLO_324 * ((t_sample)0.001)));
			t_sample wBandSolo = ((m_hBandSolo_21 <= ((int)0)) ? ((int)0) : ((m_hBandSolo_21 >= ((int)1)) ? ((int)1) : m_hBandSolo_21));
			m_hSafeLimitOn_20 = ((m_hSafeLimitOn_20 * ((t_sample)0.999)) + (m_p_SAFELIMITON_323 * ((t_sample)0.001)));
			t_sample safeOn = ((m_hSafeLimitOn_20 <= ((int)0)) ? ((int)0) : ((m_hSafeLimitOn_20 >= ((int)1)) ? ((int)1) : m_hSafeLimitOn_20));
			m_hToneOn_19 = ((m_hToneOn_19 * ((t_sample)0.9)) + (m_q_TONEON_322 * ((t_sample)0.1)));
			t_sample toneOn = ((m_hToneOn_19 <= ((int)0)) ? ((int)0) : ((m_hToneOn_19 >= ((int)1)) ? ((int)1) : m_hToneOn_19));
			m_hToneFreq_18 = ((m_hToneFreq_18 * ((t_sample)0.999)) + (m_r_TONEFREQ_321 * ((t_sample)0.001)));
			t_sample toneFreq = m_hToneFreq_18;
			m_hToneQ_9 = ((m_hToneQ_9 * ((t_sample)0.999)) + (m_t_TONEQ_320 * ((t_sample)0.001)));
			t_sample tq = ((m_hToneQ_9 <= ((t_sample)0.125)) ? ((t_sample)0.125) : ((m_hToneQ_9 >= ((int)16)) ? ((int)16) : m_hToneQ_9));
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_345 = ((minb_344 < L_loF) ? minb_344 : L_loF);
			t_sample L_loF_2735 = ((((int)10) < maxb_345) ? maxb_345 : ((int)10));
			t_sample maxb_347 = ((minb_346 < L_hiF) ? minb_346 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_347) ? maxb_347 : ((int)10));
			t_sample maxb_348 = (L_loF_2735 + ((int)1));
			t_sample L_hiF_2736 = ((L_hiFr < maxb_348) ? maxb_348 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_2735), L_sr);
			t_sample L_cos_lo = cos(L_w0_lo);
			t_sample L_sin_lo = sin(L_w0_lo);
			t_sample L_alpha_lo = (L_sin_lo * ((t_sample)0.70710678118655));
			t_sample L_a0_lo = (((int)1) + L_alpha_lo);
			t_sample L_a1_lo = (((int)-2) * L_cos_lo);
			t_sample L_a2_lo = (((int)1) - L_alpha_lo);
			t_sample L_lp_b0_l = safediv(((((int)1) - L_cos_lo) * ((t_sample)0.5)), L_a0_lo);
			t_sample L_lp_b1_l = safediv((((int)1) - L_cos_lo), L_a0_lo);
			t_sample L_lp_b2_l = L_lp_b0_l;
			t_sample L_lp_a1_l = safediv(L_a1_lo, L_a0_lo);
			t_sample L_lp_a2_l = safediv(L_a2_lo, L_a0_lo);
			t_sample L_hp_b0_l = safediv(((((int)1) + L_cos_lo) * ((t_sample)0.5)), L_a0_lo);
			t_sample L_hp_b1_l = safediv((-(((int)1) + L_cos_lo)), L_a0_lo);
			t_sample L_hp_b2_l = L_hp_b0_l;
			t_sample L_hp_a1_l = L_lp_a1_l;
			t_sample L_hp_a2_l = L_lp_a2_l;
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_2736), L_sr);
			t_sample L_cos_hi = cos(L_w0_hi);
			t_sample L_sin_hi = sin(L_w0_hi);
			t_sample L_alpha_hi = (L_sin_hi * ((t_sample)0.70710678118655));
			t_sample L_a0_hi = (((int)1) + L_alpha_hi);
			t_sample L_a1_hi = (((int)-2) * L_cos_hi);
			t_sample L_a2_hi = (((int)1) - L_alpha_hi);
			t_sample L_lp_b0_h = safediv(((((int)1) - L_cos_hi) * ((t_sample)0.5)), L_a0_hi);
			t_sample L_lp_b1_h = safediv((((int)1) - L_cos_hi), L_a0_hi);
			t_sample L_lp_b2_h = L_lp_b0_h;
			t_sample L_lp_a1_h = safediv(L_a1_hi, L_a0_hi);
			t_sample L_lp_a2_h = safediv(L_a2_hi, L_a0_hi);
			t_sample L_hp_b0_h = safediv(((((int)1) + L_cos_hi) * ((t_sample)0.5)), L_a0_hi);
			t_sample L_hp_b1_h = safediv((-(((int)1) + L_cos_hi)), L_a0_hi);
			t_sample L_hp_b2_h = L_hp_b0_h;
			t_sample L_hp_a1_h = L_lp_a1_h;
			t_sample L_hp_a2_h = L_lp_a2_h;
			t_sample L_l1_x1p = fixdenorm(m_L_l1_x_62);
			t_sample L_l1_x2p = fixdenorm(m_L_l1_x_319);
			t_sample L_l1_y1p = fixdenorm(m_L_l1_y_318);
			t_sample L_l1_y2p = fixdenorm(m_L_l1_y_317);
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_319 = L_l1_x1p;
			m_L_l1_x_62 = L_x;
			m_L_l1_y_317 = L_l1_y1p;
			m_L_l1_y_318 = L_low_s1;
			t_sample L_l2_x1p = fixdenorm(m_L_l2_x_60);
			t_sample L_l2_x2p = fixdenorm(m_L_l2_x_316);
			t_sample L_l2_y1p = fixdenorm(m_L_l2_y_315);
			t_sample L_l2_y2p = fixdenorm(m_L_l2_y_314);
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_316 = L_l2_x1p;
			m_L_l2_x_60 = L_low_s1;
			m_L_l2_y_314 = L_l2_y1p;
			m_L_l2_y_315 = L_low_raw;
			t_sample L_h1_x1p = fixdenorm(m_L_h1_x_58);
			t_sample L_h1_x2p = fixdenorm(m_L_h1_x_313);
			t_sample L_h1_y1p = fixdenorm(m_L_h1_y_312);
			t_sample L_h1_y2p = fixdenorm(m_L_h1_y_311);
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_313 = L_h1_x1p;
			m_L_h1_x_58 = L_x;
			m_L_h1_y_311 = L_h1_y1p;
			m_L_h1_y_312 = L_rest_s1;
			t_sample L_h2_x1p = fixdenorm(m_L_h2_x_56);
			t_sample L_h2_x2p = fixdenorm(m_L_h2_x_310);
			t_sample L_h2_y1p = fixdenorm(m_L_h2_y_309);
			t_sample L_h2_y2p = fixdenorm(m_L_h2_y_308);
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_310 = L_h2_x1p;
			m_L_h2_x_56 = L_rest_s1;
			m_L_h2_y_308 = L_h2_y1p;
			m_L_h2_y_309 = L_rest;
			t_sample L_ap_low_lp1_x1p = fixdenorm(m_L_ap_low_lp1_x_46);
			t_sample L_ap_low_lp1_x2p = fixdenorm(m_L_ap_low_lp1_x_295);
			t_sample L_ap_low_lp1_y1p = fixdenorm(m_L_ap_low_lp1_y_294);
			t_sample L_ap_low_lp1_y2p = fixdenorm(m_L_ap_low_lp1_y_293);
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_295 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_46 = L_low_raw;
			m_L_ap_low_lp1_y_293 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_294 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = fixdenorm(m_L_ap_low_lp2_x_44);
			t_sample L_ap_low_lp2_x2p = fixdenorm(m_L_ap_low_lp2_x_292);
			t_sample L_ap_low_lp2_y1p = fixdenorm(m_L_ap_low_lp2_y_291);
			t_sample L_ap_low_lp2_y2p = fixdenorm(m_L_ap_low_lp2_y_290);
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_292 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_44 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_290 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_291 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = fixdenorm(m_L_ap_low_hp1_x_42);
			t_sample L_ap_low_hp1_x2p = fixdenorm(m_L_ap_low_hp1_x_289);
			t_sample L_ap_low_hp1_y1p = fixdenorm(m_L_ap_low_hp1_y_288);
			t_sample L_ap_low_hp1_y2p = fixdenorm(m_L_ap_low_hp1_y_287);
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_289 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_42 = L_low_raw;
			m_L_ap_low_hp1_y_287 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_288 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = fixdenorm(m_L_ap_low_hp2_x_40);
			t_sample L_ap_low_hp2_x2p = fixdenorm(m_L_ap_low_hp2_x_286);
			t_sample L_ap_low_hp2_y1p = fixdenorm(m_L_ap_low_hp2_y_285);
			t_sample L_ap_low_hp2_y2p = fixdenorm(m_L_ap_low_hp2_y_284);
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_286 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_40 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_284 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_285 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = fixdenorm(m_L_m1_x_54);
			t_sample L_m1_x2p = fixdenorm(m_L_m1_x_307);
			t_sample L_m1_y1p = fixdenorm(m_L_m1_y_306);
			t_sample L_m1_y2p = fixdenorm(m_L_m1_y_305);
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_307 = L_m1_x1p;
			m_L_m1_x_54 = L_rest;
			m_L_m1_y_305 = L_m1_y1p;
			m_L_m1_y_306 = L_mid_s1;
			t_sample L_m2_x1p = fixdenorm(m_L_m2_x_52);
			t_sample L_m2_x2p = fixdenorm(m_L_m2_x_304);
			t_sample L_m2_y1p = fixdenorm(m_L_m2_y_303);
			t_sample L_m2_y2p = fixdenorm(m_L_m2_y_302);
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_304 = L_m2_x1p;
			m_L_m2_x_52 = L_mid_s1;
			m_L_m2_y_302 = L_m2_y1p;
			m_L_m2_y_303 = L_mid;
			t_sample L_u1_x1p = fixdenorm(m_L_u1_x_50);
			t_sample L_u1_x2p = fixdenorm(m_L_u1_x_301);
			t_sample L_u1_y1p = fixdenorm(m_L_u1_y_300);
			t_sample L_u1_y2p = fixdenorm(m_L_u1_y_299);
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_301 = L_u1_x1p;
			m_L_u1_x_50 = L_rest;
			m_L_u1_y_299 = L_u1_y1p;
			m_L_u1_y_300 = L_high_s1;
			t_sample L_u2_x1p = fixdenorm(m_L_u2_x_48);
			t_sample L_u2_x2p = fixdenorm(m_L_u2_x_298);
			t_sample L_u2_y1p = fixdenorm(m_L_u2_y_297);
			t_sample L_u2_y2p = fixdenorm(m_L_u2_y_296);
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_298 = L_u2_x1p;
			m_L_u2_x_48 = L_high_s1;
			m_L_u2_y_296 = L_u2_y1p;
			m_L_u2_y_297 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_350 = ((minb_349 < R_loF) ? minb_349 : R_loF);
			t_sample R_loF_2737 = ((((int)10) < maxb_350) ? maxb_350 : ((int)10));
			t_sample maxb_352 = ((minb_351 < R_hiF) ? minb_351 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_352) ? maxb_352 : ((int)10));
			t_sample maxb_353 = (R_loF_2737 + ((int)1));
			t_sample R_hiF_2738 = ((R_hiFr < maxb_353) ? maxb_353 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_2737), R_sr);
			t_sample R_cos_lo = cos(R_w0_lo);
			t_sample R_sin_lo = sin(R_w0_lo);
			t_sample R_alpha_lo = (R_sin_lo * ((t_sample)0.70710678118655));
			t_sample R_a0_lo = (((int)1) + R_alpha_lo);
			t_sample R_a1_lo = (((int)-2) * R_cos_lo);
			t_sample R_a2_lo = (((int)1) - R_alpha_lo);
			t_sample R_lp_b0_l = safediv(((((int)1) - R_cos_lo) * ((t_sample)0.5)), R_a0_lo);
			t_sample R_lp_b1_l = safediv((((int)1) - R_cos_lo), R_a0_lo);
			t_sample R_lp_b2_l = R_lp_b0_l;
			t_sample R_lp_a1_l = safediv(R_a1_lo, R_a0_lo);
			t_sample R_lp_a2_l = safediv(R_a2_lo, R_a0_lo);
			t_sample R_hp_b0_l = safediv(((((int)1) + R_cos_lo) * ((t_sample)0.5)), R_a0_lo);
			t_sample R_hp_b1_l = safediv((-(((int)1) + R_cos_lo)), R_a0_lo);
			t_sample R_hp_b2_l = R_hp_b0_l;
			t_sample R_hp_a1_l = R_lp_a1_l;
			t_sample R_hp_a2_l = R_lp_a2_l;
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_2738), R_sr);
			t_sample R_cos_hi = cos(R_w0_hi);
			t_sample R_sin_hi = sin(R_w0_hi);
			t_sample R_alpha_hi = (R_sin_hi * ((t_sample)0.70710678118655));
			t_sample R_a0_hi = (((int)1) + R_alpha_hi);
			t_sample R_a1_hi = (((int)-2) * R_cos_hi);
			t_sample R_a2_hi = (((int)1) - R_alpha_hi);
			t_sample R_lp_b0_h = safediv(((((int)1) - R_cos_hi) * ((t_sample)0.5)), R_a0_hi);
			t_sample R_lp_b1_h = safediv((((int)1) - R_cos_hi), R_a0_hi);
			t_sample R_lp_b2_h = R_lp_b0_h;
			t_sample R_lp_a1_h = safediv(R_a1_hi, R_a0_hi);
			t_sample R_lp_a2_h = safediv(R_a2_hi, R_a0_hi);
			t_sample R_hp_b0_h = safediv(((((int)1) + R_cos_hi) * ((t_sample)0.5)), R_a0_hi);
			t_sample R_hp_b1_h = safediv((-(((int)1) + R_cos_hi)), R_a0_hi);
			t_sample R_hp_b2_h = R_hp_b0_h;
			t_sample R_hp_a1_h = R_lp_a1_h;
			t_sample R_hp_a2_h = R_lp_a2_h;
			t_sample R_l1_x1p = fixdenorm(m_R_l1_x_61);
			t_sample R_l1_x2p = fixdenorm(m_R_l1_x_259);
			t_sample R_l1_y1p = fixdenorm(m_R_l1_y_258);
			t_sample R_l1_y2p = fixdenorm(m_R_l1_y_257);
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_259 = R_l1_x1p;
			m_R_l1_x_61 = R_x;
			m_R_l1_y_257 = R_l1_y1p;
			m_R_l1_y_258 = R_low_s1;
			t_sample R_l2_x1p = fixdenorm(m_R_l2_x_59);
			t_sample R_l2_x2p = fixdenorm(m_R_l2_x_256);
			t_sample R_l2_y1p = fixdenorm(m_R_l2_y_255);
			t_sample R_l2_y2p = fixdenorm(m_R_l2_y_254);
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_256 = R_l2_x1p;
			m_R_l2_x_59 = R_low_s1;
			m_R_l2_y_254 = R_l2_y1p;
			m_R_l2_y_255 = R_low_raw;
			t_sample R_h1_x1p = fixdenorm(m_R_h1_x_57);
			t_sample R_h1_x2p = fixdenorm(m_R_h1_x_253);
			t_sample R_h1_y1p = fixdenorm(m_R_h1_y_252);
			t_sample R_h1_y2p = fixdenorm(m_R_h1_y_251);
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_253 = R_h1_x1p;
			m_R_h1_x_57 = R_x;
			m_R_h1_y_251 = R_h1_y1p;
			m_R_h1_y_252 = R_rest_s1;
			t_sample R_h2_x1p = fixdenorm(m_R_h2_x_55);
			t_sample R_h2_x2p = fixdenorm(m_R_h2_x_250);
			t_sample R_h2_y1p = fixdenorm(m_R_h2_y_249);
			t_sample R_h2_y2p = fixdenorm(m_R_h2_y_248);
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_250 = R_h2_x1p;
			m_R_h2_x_55 = R_rest_s1;
			m_R_h2_y_248 = R_h2_y1p;
			m_R_h2_y_249 = R_rest;
			t_sample R_ap_low_lp1_x1p = fixdenorm(m_R_ap_low_lp1_x_45);
			t_sample R_ap_low_lp1_x2p = fixdenorm(m_R_ap_low_lp1_x_235);
			t_sample R_ap_low_lp1_y1p = fixdenorm(m_R_ap_low_lp1_y_234);
			t_sample R_ap_low_lp1_y2p = fixdenorm(m_R_ap_low_lp1_y_233);
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_235 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_45 = R_low_raw;
			m_R_ap_low_lp1_y_233 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_234 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = fixdenorm(m_R_ap_low_lp2_x_43);
			t_sample R_ap_low_lp2_x2p = fixdenorm(m_R_ap_low_lp2_x_232);
			t_sample R_ap_low_lp2_y1p = fixdenorm(m_R_ap_low_lp2_y_231);
			t_sample R_ap_low_lp2_y2p = fixdenorm(m_R_ap_low_lp2_y_230);
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_232 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_43 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_230 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_231 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = fixdenorm(m_R_ap_low_hp1_x_41);
			t_sample R_ap_low_hp1_x2p = fixdenorm(m_R_ap_low_hp1_x_229);
			t_sample R_ap_low_hp1_y1p = fixdenorm(m_R_ap_low_hp1_y_228);
			t_sample R_ap_low_hp1_y2p = fixdenorm(m_R_ap_low_hp1_y_227);
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_229 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_41 = R_low_raw;
			m_R_ap_low_hp1_y_227 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_228 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = fixdenorm(m_R_ap_low_hp2_x_39);
			t_sample R_ap_low_hp2_x2p = fixdenorm(m_R_ap_low_hp2_x_226);
			t_sample R_ap_low_hp2_y1p = fixdenorm(m_R_ap_low_hp2_y_225);
			t_sample R_ap_low_hp2_y2p = fixdenorm(m_R_ap_low_hp2_y_224);
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_226 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_39 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_224 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_225 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = fixdenorm(m_R_m1_x_53);
			t_sample R_m1_x2p = fixdenorm(m_R_m1_x_247);
			t_sample R_m1_y1p = fixdenorm(m_R_m1_y_246);
			t_sample R_m1_y2p = fixdenorm(m_R_m1_y_245);
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_247 = R_m1_x1p;
			m_R_m1_x_53 = R_rest;
			m_R_m1_y_245 = R_m1_y1p;
			m_R_m1_y_246 = R_mid_s1;
			t_sample R_m2_x1p = fixdenorm(m_R_m2_x_51);
			t_sample R_m2_x2p = fixdenorm(m_R_m2_x_244);
			t_sample R_m2_y1p = fixdenorm(m_R_m2_y_243);
			t_sample R_m2_y2p = fixdenorm(m_R_m2_y_242);
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_244 = R_m2_x1p;
			m_R_m2_x_51 = R_mid_s1;
			m_R_m2_y_242 = R_m2_y1p;
			m_R_m2_y_243 = R_mid;
			t_sample R_u1_x1p = fixdenorm(m_R_u1_x_49);
			t_sample R_u1_x2p = fixdenorm(m_R_u1_x_241);
			t_sample R_u1_y1p = fixdenorm(m_R_u1_y_240);
			t_sample R_u1_y2p = fixdenorm(m_R_u1_y_239);
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_241 = R_u1_x1p;
			m_R_u1_x_49 = R_rest;
			m_R_u1_y_239 = R_u1_y1p;
			m_R_u1_y_240 = R_high_s1;
			t_sample R_u2_x1p = fixdenorm(m_R_u2_x_47);
			t_sample R_u2_x2p = fixdenorm(m_R_u2_x_238);
			t_sample R_u2_y1p = fixdenorm(m_R_u2_y_237);
			t_sample R_u2_y2p = fixdenorm(m_R_u2_y_236);
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_238 = R_u2_x1p;
			m_R_u2_x_47 = R_high_s1;
			m_R_u2_y_236 = R_u2_y1p;
			m_R_u2_y_237 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_354 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_354) ? maxb_354 : ((int)0));
			t_sample maxb_355 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_355) ? maxb_355 : ((int)0));
			t_sample maxb_356 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_356) ? maxb_356 : ((int)0));
			t_sample maxb_357 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_357) ? maxb_357 : ((t_sample)1e-09));
			t_sample wLow_2739 = safediv(wLow, wSum);
			t_sample wMid_2740 = safediv(wMid, wSum);
			t_sample wHigh_2741 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_2739 * lowL) + (wMid_2740 * midL)) + (wHigh_2741 * highL));
			t_sample preBandR = (((wLow_2739 * lowR) + (wMid_2740 * midR)) + (wHigh_2741 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			int soloOn = ((wBandSolo > ((t_sample)0.5)) * (scSm > ((t_sample)0.5)));
			t_sample iffalse_358 = (sumBandsL - preBandL);
			t_sample bypassWhenActiveL = (soloOn ? ((int)0) : iffalse_358);
			t_sample iffalse_359 = (sumBandsR - preBandR);
			t_sample bypassWhenActiveR = (soloOn ? ((int)0) : iffalse_359);
			t_sample mix_2891 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_2891;
			t_sample mix_2892 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_2892;
			t_sample L_loF_2742 = smoothHpfFreq;
			t_sample L_hiF_2743 = smoothLpfFreq;
			t_sample L_x_2744 = lIn;
			t_sample maxb_361 = ((minb_360 < L_loF_2742) ? minb_360 : L_loF_2742);
			t_sample L_loF_2747 = ((((int)10) < maxb_361) ? maxb_361 : ((int)10));
			t_sample maxb_363 = ((minb_362 < L_hiF_2743) ? minb_362 : L_hiF_2743);
			t_sample L_hiFr_2748 = ((((int)10) < maxb_363) ? maxb_363 : ((int)10));
			t_sample maxb_364 = (L_loF_2747 + ((int)1));
			t_sample L_hiF_2749 = ((L_hiFr_2748 < maxb_364) ? maxb_364 : L_hiFr_2748);
			t_sample L_w0_lo_2750 = safediv((((t_sample)6.2831853071796) * L_loF_2747), L_sr_2746);
			t_sample L_cos_lo_2751 = cos(L_w0_lo_2750);
			t_sample L_sin_lo_2752 = sin(L_w0_lo_2750);
			t_sample L_alpha_lo_2753 = (L_sin_lo_2752 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_2754 = (((int)1) + L_alpha_lo_2753);
			t_sample L_a1_lo_2755 = (((int)-2) * L_cos_lo_2751);
			t_sample L_a2_lo_2756 = (((int)1) - L_alpha_lo_2753);
			t_sample L_lp_b0_l_2757 = safediv(((((int)1) - L_cos_lo_2751) * ((t_sample)0.5)), L_a0_lo_2754);
			t_sample L_lp_b1_l_2758 = safediv((((int)1) - L_cos_lo_2751), L_a0_lo_2754);
			t_sample L_lp_b2_l_2759 = L_lp_b0_l_2757;
			t_sample L_lp_a1_l_2760 = safediv(L_a1_lo_2755, L_a0_lo_2754);
			t_sample L_lp_a2_l_2761 = safediv(L_a2_lo_2756, L_a0_lo_2754);
			t_sample L_hp_b0_l_2762 = safediv(((((int)1) + L_cos_lo_2751) * ((t_sample)0.5)), L_a0_lo_2754);
			t_sample L_hp_b1_l_2763 = safediv((-(((int)1) + L_cos_lo_2751)), L_a0_lo_2754);
			t_sample L_hp_b2_l_2764 = L_hp_b0_l_2762;
			t_sample L_hp_a1_l_2765 = L_lp_a1_l_2760;
			t_sample L_hp_a2_l_2766 = L_lp_a2_l_2761;
			t_sample L_w0_hi_2767 = safediv((((t_sample)6.2831853071796) * L_hiF_2749), L_sr_2746);
			t_sample L_cos_hi_2768 = cos(L_w0_hi_2767);
			t_sample L_sin_hi_2769 = sin(L_w0_hi_2767);
			t_sample L_alpha_hi_2770 = (L_sin_hi_2769 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_2771 = (((int)1) + L_alpha_hi_2770);
			t_sample L_a1_hi_2772 = (((int)-2) * L_cos_hi_2768);
			t_sample L_a2_hi_2773 = (((int)1) - L_alpha_hi_2770);
			t_sample L_lp_b0_h_2774 = safediv(((((int)1) - L_cos_hi_2768) * ((t_sample)0.5)), L_a0_hi_2771);
			t_sample L_lp_b1_h_2775 = safediv((((int)1) - L_cos_hi_2768), L_a0_hi_2771);
			t_sample L_lp_b2_h_2776 = L_lp_b0_h_2774;
			t_sample L_lp_a1_h_2777 = safediv(L_a1_hi_2772, L_a0_hi_2771);
			t_sample L_lp_a2_h_2778 = safediv(L_a2_hi_2773, L_a0_hi_2771);
			t_sample L_hp_b0_h_2779 = safediv(((((int)1) + L_cos_hi_2768) * ((t_sample)0.5)), L_a0_hi_2771);
			t_sample L_hp_b1_h_2780 = safediv((-(((int)1) + L_cos_hi_2768)), L_a0_hi_2771);
			t_sample L_hp_b2_h_2781 = L_hp_b0_h_2779;
			t_sample L_hp_a1_h_2782 = L_lp_a1_h_2777;
			t_sample L_hp_a2_h_2783 = L_lp_a2_h_2778;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_38;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_283;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_282;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_281;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_2757 * L_x_2744) + (L_lp_b1_l_2758 * L_ap1_lp1_x1p)) + (L_lp_b2_l_2759 * L_ap1_lp1_x2p)) - (L_lp_a1_l_2760 * L_ap1_lp1_y1p)) - (L_lp_a2_l_2761 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_283 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_38 = L_x_2744;
			m_L_ap1_lp1_y_281 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_282 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_36;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_280;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_279;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_278;
			t_sample L_ap1_lp = (((((L_lp_b0_l_2757 * L_ap1_lp_s1) + (L_lp_b1_l_2758 * L_ap1_lp2_x1p)) + (L_lp_b2_l_2759 * L_ap1_lp2_x2p)) - (L_lp_a1_l_2760 * L_ap1_lp2_y1p)) - (L_lp_a2_l_2761 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_280 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_36 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_278 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_279 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_34;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_277;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_276;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_275;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_2762 * L_x_2744) + (L_hp_b1_l_2763 * L_ap1_hp1_x1p)) + (L_hp_b2_l_2764 * L_ap1_hp1_x2p)) - (L_hp_a1_l_2765 * L_ap1_hp1_y1p)) - (L_hp_a2_l_2766 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_277 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_34 = L_x_2744;
			m_L_ap1_hp1_y_275 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_276 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_32;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_274;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_273;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_272;
			t_sample L_ap1_hp = (((((L_hp_b0_l_2762 * L_ap1_hp_s1) + (L_hp_b1_l_2763 * L_ap1_hp2_x1p)) + (L_hp_b2_l_2764 * L_ap1_hp2_x2p)) - (L_hp_a1_l_2765 * L_ap1_hp2_y1p)) - (L_hp_a2_l_2766 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_274 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_32 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_272 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_273 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_30;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_271;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_270;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_269;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_2774 * L_stage1_out) + (L_lp_b1_h_2775 * L_ap2_lp1_x1p)) + (L_lp_b2_h_2776 * L_ap2_lp1_x2p)) - (L_lp_a1_h_2777 * L_ap2_lp1_y1p)) - (L_lp_a2_h_2778 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_271 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_30 = L_stage1_out;
			m_L_ap2_lp1_y_269 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_270 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_28;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_268;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_267;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_266;
			t_sample L_ap2_lp = (((((L_lp_b0_h_2774 * L_ap2_lp_s1) + (L_lp_b1_h_2775 * L_ap2_lp2_x1p)) + (L_lp_b2_h_2776 * L_ap2_lp2_x2p)) - (L_lp_a1_h_2777 * L_ap2_lp2_y1p)) - (L_lp_a2_h_2778 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_268 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_28 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_266 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_267 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_26;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_265;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_264;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_263;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_2779 * L_stage1_out) + (L_hp_b1_h_2780 * L_ap2_hp1_x1p)) + (L_hp_b2_h_2781 * L_ap2_hp1_x2p)) - (L_hp_a1_h_2782 * L_ap2_hp1_y1p)) - (L_hp_a2_h_2783 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_265 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_26 = L_stage1_out;
			m_L_ap2_hp1_y_263 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_264 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_24;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_262;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_261;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_260;
			t_sample L_ap2_hp = (((((L_hp_b0_h_2779 * L_ap2_hp_s1) + (L_hp_b1_h_2780 * L_ap2_hp2_x1p)) + (L_hp_b2_h_2781 * L_ap2_hp2_x2p)) - (L_hp_a1_h_2782 * L_ap2_hp2_y1p)) - (L_hp_a2_h_2783 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_262 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_24 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_260 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_261 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_2784 = smoothHpfFreq;
			t_sample R_hiF_2785 = smoothLpfFreq;
			t_sample R_x_2786 = rIn;
			t_sample maxb_366 = ((minb_365 < R_loF_2784) ? minb_365 : R_loF_2784);
			t_sample R_loF_2789 = ((((int)10) < maxb_366) ? maxb_366 : ((int)10));
			t_sample maxb_368 = ((minb_367 < R_hiF_2785) ? minb_367 : R_hiF_2785);
			t_sample R_hiFr_2790 = ((((int)10) < maxb_368) ? maxb_368 : ((int)10));
			t_sample maxb_369 = (R_loF_2789 + ((int)1));
			t_sample R_hiF_2791 = ((R_hiFr_2790 < maxb_369) ? maxb_369 : R_hiFr_2790);
			t_sample R_w0_lo_2792 = safediv((((t_sample)6.2831853071796) * R_loF_2789), R_sr_2788);
			t_sample R_cos_lo_2793 = cos(R_w0_lo_2792);
			t_sample R_sin_lo_2794 = sin(R_w0_lo_2792);
			t_sample R_alpha_lo_2795 = (R_sin_lo_2794 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_2796 = (((int)1) + R_alpha_lo_2795);
			t_sample R_a1_lo_2797 = (((int)-2) * R_cos_lo_2793);
			t_sample R_a2_lo_2798 = (((int)1) - R_alpha_lo_2795);
			t_sample R_lp_b0_l_2799 = safediv(((((int)1) - R_cos_lo_2793) * ((t_sample)0.5)), R_a0_lo_2796);
			t_sample R_lp_b1_l_2800 = safediv((((int)1) - R_cos_lo_2793), R_a0_lo_2796);
			t_sample R_lp_b2_l_2801 = R_lp_b0_l_2799;
			t_sample R_lp_a1_l_2802 = safediv(R_a1_lo_2797, R_a0_lo_2796);
			t_sample R_lp_a2_l_2803 = safediv(R_a2_lo_2798, R_a0_lo_2796);
			t_sample R_hp_b0_l_2804 = safediv(((((int)1) + R_cos_lo_2793) * ((t_sample)0.5)), R_a0_lo_2796);
			t_sample R_hp_b1_l_2805 = safediv((-(((int)1) + R_cos_lo_2793)), R_a0_lo_2796);
			t_sample R_hp_b2_l_2806 = R_hp_b0_l_2804;
			t_sample R_hp_a1_l_2807 = R_lp_a1_l_2802;
			t_sample R_hp_a2_l_2808 = R_lp_a2_l_2803;
			t_sample R_w0_hi_2809 = safediv((((t_sample)6.2831853071796) * R_hiF_2791), R_sr_2788);
			t_sample R_cos_hi_2810 = cos(R_w0_hi_2809);
			t_sample R_sin_hi_2811 = sin(R_w0_hi_2809);
			t_sample R_alpha_hi_2812 = (R_sin_hi_2811 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_2813 = (((int)1) + R_alpha_hi_2812);
			t_sample R_a1_hi_2814 = (((int)-2) * R_cos_hi_2810);
			t_sample R_a2_hi_2815 = (((int)1) - R_alpha_hi_2812);
			t_sample R_lp_b0_h_2816 = safediv(((((int)1) - R_cos_hi_2810) * ((t_sample)0.5)), R_a0_hi_2813);
			t_sample R_lp_b1_h_2817 = safediv((((int)1) - R_cos_hi_2810), R_a0_hi_2813);
			t_sample R_lp_b2_h_2818 = R_lp_b0_h_2816;
			t_sample R_lp_a1_h_2819 = safediv(R_a1_hi_2814, R_a0_hi_2813);
			t_sample R_lp_a2_h_2820 = safediv(R_a2_hi_2815, R_a0_hi_2813);
			t_sample R_hp_b0_h_2821 = safediv(((((int)1) + R_cos_hi_2810) * ((t_sample)0.5)), R_a0_hi_2813);
			t_sample R_hp_b1_h_2822 = safediv((-(((int)1) + R_cos_hi_2810)), R_a0_hi_2813);
			t_sample R_hp_b2_h_2823 = R_hp_b0_h_2821;
			t_sample R_hp_a1_h_2824 = R_lp_a1_h_2819;
			t_sample R_hp_a2_h_2825 = R_lp_a2_h_2820;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_37;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_223;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_222;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_221;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_2799 * R_x_2786) + (R_lp_b1_l_2800 * R_ap1_lp1_x1p)) + (R_lp_b2_l_2801 * R_ap1_lp1_x2p)) - (R_lp_a1_l_2802 * R_ap1_lp1_y1p)) - (R_lp_a2_l_2803 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_223 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_37 = R_x_2786;
			m_R_ap1_lp1_y_221 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_222 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_35;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_220;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_219;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_218;
			t_sample R_ap1_lp = (((((R_lp_b0_l_2799 * R_ap1_lp_s1) + (R_lp_b1_l_2800 * R_ap1_lp2_x1p)) + (R_lp_b2_l_2801 * R_ap1_lp2_x2p)) - (R_lp_a1_l_2802 * R_ap1_lp2_y1p)) - (R_lp_a2_l_2803 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_220 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_35 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_218 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_219 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_33;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_217;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_216;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_215;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_2804 * R_x_2786) + (R_hp_b1_l_2805 * R_ap1_hp1_x1p)) + (R_hp_b2_l_2806 * R_ap1_hp1_x2p)) - (R_hp_a1_l_2807 * R_ap1_hp1_y1p)) - (R_hp_a2_l_2808 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_217 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_33 = R_x_2786;
			m_R_ap1_hp1_y_215 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_216 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_31;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_214;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_213;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_212;
			t_sample R_ap1_hp = (((((R_hp_b0_l_2804 * R_ap1_hp_s1) + (R_hp_b1_l_2805 * R_ap1_hp2_x1p)) + (R_hp_b2_l_2806 * R_ap1_hp2_x2p)) - (R_hp_a1_l_2807 * R_ap1_hp2_y1p)) - (R_hp_a2_l_2808 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_214 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_31 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_212 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_213 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_29;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_211;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_210;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_209;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_2816 * R_stage1_out) + (R_lp_b1_h_2817 * R_ap2_lp1_x1p)) + (R_lp_b2_h_2818 * R_ap2_lp1_x2p)) - (R_lp_a1_h_2819 * R_ap2_lp1_y1p)) - (R_lp_a2_h_2820 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_211 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_29 = R_stage1_out;
			m_R_ap2_lp1_y_209 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_210 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_27;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_208;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_207;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_206;
			t_sample R_ap2_lp = (((((R_lp_b0_h_2816 * R_ap2_lp_s1) + (R_lp_b1_h_2817 * R_ap2_lp2_x1p)) + (R_lp_b2_h_2818 * R_ap2_lp2_x2p)) - (R_lp_a1_h_2819 * R_ap2_lp2_y1p)) - (R_lp_a2_h_2820 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_208 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_27 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_206 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_207 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_25;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_205;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_204;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_203;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_2821 * R_stage1_out) + (R_hp_b1_h_2822 * R_ap2_hp1_x1p)) + (R_hp_b2_h_2823 * R_ap2_hp1_x2p)) - (R_hp_a1_h_2824 * R_ap2_hp1_y1p)) - (R_hp_a2_h_2825 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_205 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_25 = R_stage1_out;
			m_R_ap2_hp1_y_203 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_204 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_23;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_202;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_201;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_200;
			t_sample R_ap2_hp = (((((R_hp_b0_h_2821 * R_ap2_hp_s1) + (R_hp_b1_h_2822 * R_ap2_hp2_x1p)) + (R_hp_b2_h_2823 * R_ap2_hp2_x2p)) - (R_hp_a1_h_2824 * R_ap2_hp2_y1p)) - (R_hp_a2_h_2825 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_202 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_23 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_200 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_201 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_2893 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample dryL = mix_2893;
			t_sample mix_2894 = (rIn + (scSm * (dryCompR - rIn)));
			t_sample dryR = mix_2894;
			t_sample lFiltered = preDistInL;
			t_sample rFiltered = preDistInR;
			t_sample Gls = (-tiltDb);
			t_sample Ghs = tiltDb;
			t_sample Als = sqrt(dbtoa(Gls));
			t_sample Ahs = sqrt(dbtoa(Ghs));
			t_sample alphaLs = ((((t_sample)0.5) * sn) * sqrt((((Als + safediv(((int)1), Als)) * ((int)1)) + ((int)2))));
			t_sample alphaHs = ((((t_sample)0.5) * sn) * sqrt((((Ahs + safediv(((int)1), Ahs)) * ((int)1)) + ((int)2))));
			t_sample sqrtAls = sqrt(Als);
			t_sample sqrtAhs = sqrt(Ahs);
			t_sample b0_ls = (Als * (((Als + ((int)1)) - ((Als - ((int)1)) * cs)) + ((((int)2) * sqrtAls) * alphaLs)));
			t_sample b1_ls = ((((int)2) * Als) * ((Als - ((int)1)) - ((Als + ((int)1)) * cs)));
			t_sample b2_ls = (Als * (((Als + ((int)1)) - ((Als - ((int)1)) * cs)) - ((((int)2) * sqrtAls) * alphaLs)));
			t_sample a0_ls = (((Als + ((int)1)) + ((Als - ((int)1)) * cs)) + ((((int)2) * sqrtAls) * alphaLs));
			t_sample a1_ls = (((int)-2) * ((Als - ((int)1)) + ((Als + ((int)1)) * cs)));
			t_sample a2_ls = (((Als + ((int)1)) + ((Als - ((int)1)) * cs)) - ((((int)2) * sqrtAls) * alphaLs));
			t_sample inv_a0_ls = safediv(((int)1), a0_ls);
			t_sample a0Ls = (b0_ls * inv_a0_ls);
			t_sample a1Ls = (b1_ls * inv_a0_ls);
			t_sample a2Ls = (b2_ls * inv_a0_ls);
			t_sample b1Ls = (a1_ls * inv_a0_ls);
			t_sample b2Ls = (a2_ls * inv_a0_ls);
			t_sample lLs_2826 = (((((a0Ls * lFiltered) + (a1Ls * fixdenorm(m_tiltLsL_94))) + (a2Ls * fixdenorm(m_tiltLsL_95))) - (b1Ls * fixdenorm(m_tiltLsL_92))) - (b2Ls * fixdenorm(m_tiltLsL_93)));
			m_tiltLsL_95 = m_tiltLsL_94;
			m_tiltLsL_94 = lFiltered;
			m_tiltLsL_93 = m_tiltLsL_92;
			m_tiltLsL_92 = lLs_2826;
			t_sample rLs_2827 = (((((a0Ls * rFiltered) + (a1Ls * fixdenorm(m_tiltLsR_90))) + (a2Ls * fixdenorm(m_tiltLsR_91))) - (b1Ls * fixdenorm(m_tiltLsR_88))) - (b2Ls * fixdenorm(m_tiltLsR_89)));
			m_tiltLsR_91 = m_tiltLsR_90;
			m_tiltLsR_90 = rFiltered;
			m_tiltLsR_89 = m_tiltLsR_88;
			m_tiltLsR_88 = rLs_2827;
			t_sample b0_hs = (Ahs * (((Ahs + ((int)1)) + ((Ahs - ((int)1)) * cs)) + ((((int)2) * sqrtAhs) * alphaHs)));
			t_sample b1_hs = ((((int)-2) * Ahs) * ((Ahs - ((int)1)) + ((Ahs + ((int)1)) * cs)));
			t_sample b2_hs = (Ahs * (((Ahs + ((int)1)) + ((Ahs - ((int)1)) * cs)) - ((((int)2) * sqrtAhs) * alphaHs)));
			t_sample a0_hs = (((Ahs + ((int)1)) - ((Ahs - ((int)1)) * cs)) + ((((int)2) * sqrtAhs) * alphaHs));
			t_sample a1_hs = (((int)2) * ((Ahs - ((int)1)) - ((Ahs + ((int)1)) * cs)));
			t_sample a2_hs = (((Ahs + ((int)1)) - ((Ahs - ((int)1)) * cs)) - ((((int)2) * sqrtAhs) * alphaHs));
			t_sample inv_a0_hs = safediv(((int)1), a0_hs);
			t_sample a0Hs = (b0_hs * inv_a0_hs);
			t_sample a1Hs = (b1_hs * inv_a0_hs);
			t_sample a2Hs = (b2_hs * inv_a0_hs);
			t_sample b1Hs = (a1_hs * inv_a0_hs);
			t_sample b2Hs = (a2_hs * inv_a0_hs);
			t_sample lTiltRaw = (((((a0Hs * lLs_2826) + (a1Hs * fixdenorm(m_tiltHsL_86))) + (a2Hs * fixdenorm(m_tiltHsL_87))) - (b1Hs * fixdenorm(m_tiltHsL_84))) - (b2Hs * fixdenorm(m_tiltHsL_85)));
			m_tiltHsL_87 = m_tiltHsL_86;
			m_tiltHsL_86 = lLs_2826;
			m_tiltHsL_85 = m_tiltHsL_84;
			m_tiltHsL_84 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_2827) + (a1Hs * fixdenorm(m_tiltHsR_82))) + (a2Hs * fixdenorm(m_tiltHsR_83))) - (b1Hs * fixdenorm(m_tiltHsR_80))) - (b2Hs * fixdenorm(m_tiltHsR_81)));
			m_tiltHsR_83 = m_tiltHsR_82;
			m_tiltHsR_82 = rLs_2827;
			m_tiltHsR_81 = m_tiltHsR_80;
			m_tiltHsR_80 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cosw)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sinw) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cosw)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sinw) + (b2Ls * sin2)));
			t_sample maxb_370 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_370) ? maxb_370 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cosw)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sinw) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cosw)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sinw) + (b2Hs * sin2)));
			t_sample maxb_371 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_371) ? maxb_371 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_372 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_372) ? maxb_372 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample mode = smoothedMode;
			t_sample maxb_373 = (((int)1) - fabs((mode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_373) ? maxb_373 : ((int)0));
			t_sample maxb_374 = (((int)1) - fabs((mode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_374) ? maxb_374 : ((int)0));
			t_sample maxb_375 = (((int)1) - fabs((mode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_375) ? maxb_375 : ((int)0));
			t_sample maxb_376 = (((int)1) - fabs((mode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_376) ? maxb_376 : ((int)0));
			t_sample maxb_377 = (((int)1) - fabs((mode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_377) ? maxb_377 : ((int)0));
			t_sample maxb_378 = (((int)1) - fabs((mode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_378) ? maxb_378 : ((int)0));
			t_sample maxb_379 = (((int)1) - fabs((mode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_379) ? maxb_379 : ((int)0));
			t_sample maxb_380 = (((int)1) - fabs((mode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_380) ? maxb_380 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_2828 = safediv(w0, sumWeights);
			t_sample w_2829 = safediv(w1, sumWeights);
			t_sample w_2830 = safediv(w2, sumWeights);
			t_sample w_2831 = safediv(w3, sumWeights);
			t_sample w_2832 = safediv(w4, sumWeights);
			t_sample w_2833 = safediv(w5, sumWeights);
			t_sample w_2834 = safediv(w6, sumWeights);
			t_sample w_2835 = safediv(w7, sumWeights);
			t_sample dcNorm = ((m_hDc_117 * ((int)2)) - ((int)1));
			t_sample dcSkew = (tanh((dcNorm * ((int)3))) * ((t_sample)0.4));
			t_sample return_389;
			t_sample return_390;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_389, return_390);
			t_sample softL_A = return_389;
			t_sample softR_A = return_390;
			t_sample return_401;
			t_sample return_402;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_401, return_402);
			t_sample sigmL_A = return_401;
			t_sample sigmR_A = return_402;
			t_sample return_411;
			t_sample return_412;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_411, return_412);
			t_sample rectL_A = return_411;
			t_sample rectR_A = return_412;
			t_sample return_421;
			t_sample return_422;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_421, return_422);
			t_sample fuzz1L_A = return_421;
			t_sample fuzz1R_A = return_422;
			t_sample return_437;
			t_sample return_438;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_437, return_438);
			t_sample tanhL_A = return_437;
			t_sample tanhR_A = return_438;
			t_sample return_445;
			t_sample return_446;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_445, return_446);
			t_sample recthL_A = return_445;
			t_sample recthR_A = return_446;
			t_sample return_453;
			t_sample return_454;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_453, return_454);
			t_sample atanL_A = return_453;
			t_sample atanR_A = return_454;
			t_sample return_469;
			t_sample return_470;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_469, return_470);
			t_sample hardL_A = return_469;
			t_sample hardR_A = return_470;
			t_sample distL_A = ((((((((softL_A * w_2828) + (sigmL_A * w_2829)) + (rectL_A * w_2830)) + (fuzz1L_A * w_2831)) + (tanhL_A * w_2832)) + (recthL_A * w_2833)) + (atanL_A * w_2834)) + (hardL_A * w_2835));
			t_sample distR_A = ((((((((softR_A * w_2828) + (sigmR_A * w_2829)) + (rectR_A * w_2830)) + (fuzz1R_A * w_2831)) + (tanhR_A * w_2832)) + (recthR_A * w_2833)) + (atanR_A * w_2834)) + (hardR_A * w_2835));
			t_sample preOutL = __m_dcblock_471(distL_A);
			t_sample preOutR = __m_dcblock_472(distR_A);
			t_sample return_473;
			t_sample return_474;
			softclip_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_473, return_474);
			t_sample softL_B = return_473;
			t_sample softR_B = return_474;
			t_sample return_475;
			t_sample return_476;
			sigmoid_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_475, return_476);
			t_sample sigmL_B = return_475;
			t_sample sigmR_B = return_476;
			t_sample return_477;
			t_sample return_478;
			rectF_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_477, return_478);
			t_sample rectL_B = return_477;
			t_sample rectR_B = return_478;
			t_sample return_479;
			t_sample return_480;
			fuzzExp1_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_479, return_480);
			t_sample fuzz1L_B = return_479;
			t_sample fuzz1R_B = return_480;
			t_sample return_481;
			t_sample return_482;
			tangenteHiperbolica_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_481, return_482);
			t_sample tanhL_B = return_481;
			t_sample tanhR_B = return_482;
			t_sample return_483;
			t_sample return_484;
			rectH_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_483, return_484);
			t_sample recthL_B = return_483;
			t_sample recthR_B = return_484;
			t_sample return_485;
			t_sample return_486;
			arctangent_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_485, return_486);
			t_sample atanL_B = return_485;
			t_sample atanR_B = return_486;
			t_sample return_487;
			t_sample return_488;
			hardClip_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_487, return_488);
			t_sample hardL_B = return_487;
			t_sample hardR_B = return_488;
			t_sample distL_B = ((((((((softL_B * w_2828) + (sigmL_B * w_2829)) + (rectL_B * w_2830)) + (fuzz1L_B * w_2831)) + (tanhL_B * w_2832)) + (recthL_B * w_2833)) + (atanL_B * w_2834)) + (hardL_B * w_2835));
			t_sample distR_B = ((((((((softR_B * w_2828) + (sigmR_B * w_2829)) + (rectR_B * w_2830)) + (fuzz1R_B * w_2831)) + (tanhR_B * w_2832)) + (recthR_B * w_2833)) + (atanR_B * w_2834)) + (hardR_B * w_2835));
			t_sample postInL = __m_dcblock_489(distL_B);
			t_sample postInR = __m_dcblock_490(distR_B);
			t_sample postLsL = (((((a0Ls * postInL) + (a1Ls * m_postTiltLsL_77)) + (a2Ls * m_postTiltLsL_78)) - (b1Ls * m_postTiltLsL_75)) - (b2Ls * m_postTiltLsL_76));
			m_postTiltLsL_78 = m_postTiltLsL_77;
			m_postTiltLsL_77 = postInL;
			m_postTiltLsL_76 = m_postTiltLsL_75;
			m_postTiltLsL_75 = postLsL;
			t_sample postLsR = (((((a0Ls * postInR) + (a1Ls * m_postTiltLsR_73)) + (a2Ls * m_postTiltLsR_74)) - (b1Ls * m_postTiltLsR_71)) - (b2Ls * m_postTiltLsR_72));
			m_postTiltLsR_74 = m_postTiltLsR_73;
			m_postTiltLsR_73 = postInR;
			m_postTiltLsR_72 = m_postTiltLsR_71;
			m_postTiltLsR_71 = postLsR;
			t_sample postTiltRawL = (((((a0Hs * postLsL) + (a1Hs * m_postTiltHsL_69)) + (a2Hs * m_postTiltHsL_70)) - (b1Hs * m_postTiltHsL_67)) - (b2Hs * m_postTiltHsL_68));
			m_postTiltHsL_70 = m_postTiltHsL_69;
			m_postTiltHsL_69 = postLsL;
			m_postTiltHsL_68 = m_postTiltHsL_67;
			m_postTiltHsL_67 = postTiltRawL;
			t_sample postTiltRawR = (((((a0Hs * postLsR) + (a1Hs * m_postTiltHsR_65)) + (a2Hs * m_postTiltHsR_66)) - (b1Hs * m_postTiltHsR_63)) - (b2Hs * m_postTiltHsR_64));
			m_postTiltHsR_66 = m_postTiltHsR_65;
			m_postTiltHsR_65 = postLsR;
			m_postTiltHsR_64 = m_postTiltHsR_63;
			m_postTiltHsR_63 = postTiltRawR;
			t_sample postTiltL = (postTiltRawL * gPivot);
			t_sample postTiltR = (postTiltRawR * gPivot);
			t_sample mix_2895 = (preOutL + (wPost * (postTiltL - preOutL)));
			t_sample distMorphL = mix_2895;
			t_sample mix_2896 = (preOutR + (wPost * (postTiltR - preOutR)));
			t_sample distMorphR = mix_2896;
			t_sample cleanPreTiltL = lTilt;
			t_sample cleanPreTiltR = rTilt;
			t_sample mix_2897 = (cleanPreTiltL + (wDist * (distMorphL - cleanPreTiltL)));
			t_sample processedL = mix_2897;
			t_sample mix_2898 = (cleanPreTiltR + (wDist * (distMorphR - cleanPreTiltR)));
			t_sample processedR = mix_2898;
			t_sample return_491;
			t_sample return_492;
			bitCrusher_d_d_d(processedL, processedR, bits, return_491, return_492);
			t_sample bitL = return_491;
			t_sample bitR = return_492;
			t_sample bcL = __m_dcblock_493(bitL);
			t_sample bcR = __m_dcblock_494(bitR);
			t_sample mix_2899 = (processedL + (bitson * (bcL - processedL)));
			t_sample withBitCrusherL = mix_2899;
			t_sample mix_2900 = (processedR + (bitson * (bcR - processedR)));
			t_sample withBitCrusherR = mix_2900;
			t_sample maxb_495 = floor((m_hDownsample_109 + ((int)1)));
			t_sample deciFactor = ((((int)1) < maxb_495) ? maxb_495 : ((int)1));
			int enableNow = (downsampleOn > ((t_sample)0.5));
			int enableEdge = (enableNow > m_dsEnablePrev_96);
			m_dsEnablePrev_96 = enableNow;
			t_sample inc = safediv(((int)1), deciFactor);
			t_sample iffalse_496 = (m_dsPhase_98 + inc);
			m_dsPhase_98 = (enableEdge ? ((int)0) : iffalse_496);
			m_dsPhase_98 = (m_dsPhase_98 - floor(m_dsPhase_98));
			int dsEdgeWrap = (m_dsPhase_98 < m_dsTrigPrev_97);
			int dsEdge = (((enableEdge + dsEdgeWrap) + (deciFactor == ((int)1))) > ((t_sample)0.5));
			m_dsTrigPrev_97 = m_dsPhase_98;
			__m_latch_497 = ((dsEdge != 0) ? withBitCrusherL : __m_latch_497);
			t_sample dsHeldL = __m_latch_497;
			__m_latch_498 = ((dsEdge != 0) ? withBitCrusherR : __m_latch_498);
			t_sample dsHeldR = __m_latch_498;
			t_sample mix_2901 = (withBitCrusherL + (downsampleOn * (dsHeldL - withBitCrusherL)));
			t_sample wetFinalL = mix_2901;
			t_sample mix_2902 = (withBitCrusherR + (downsampleOn * (dsHeldR - withBitCrusherR)));
			t_sample wetFinalR = mix_2902;
			t_sample wetWithMakeupL = ((wetFinalL * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((wetFinalR * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample omegaT = safediv((toneFreq * ((t_sample)6.2831853071796)), samplerate);
			t_sample sinT = sin(omegaT);
			t_sample cosT = cos(omegaT);
			t_sample alphaT = safediv(sinT, (((int)2) * tq));
			t_sample b0T = ((((int)1) - cosT) * ((t_sample)0.5));
			t_sample b1T = (((int)1) - cosT);
			t_sample b2T = ((((int)1) - cosT) * ((t_sample)0.5));
			t_sample a0T = (((int)1) + alphaT);
			t_sample a1T = (((int)-2) * cosT);
			t_sample a2T = (((int)1) - alphaT);
			t_sample inv_a0T = safediv(((int)1), a0T);
			t_sample t_a0 = (b0T * inv_a0T);
			t_sample t_a1 = (b1T * inv_a0T);
			t_sample t_a2 = (b2T * inv_a0T);
			t_sample t_b1 = (a1T * inv_a0T);
			t_sample t_b2 = (a2T * inv_a0T);
			t_sample ap_b0 = t_b2;
			t_sample ap_b1 = t_b1;
			t_sample ap_a1 = t_b1;
			t_sample ap_a2 = t_b2;
			t_sample tL_x1p = fixdenorm(m_toneL_x_17);
			t_sample tL_x2p = fixdenorm(m_toneL_x_16);
			t_sample tL_y1p = fixdenorm(m_toneL_y_15);
			t_sample tL_y2p = fixdenorm(m_toneL_y_14);
			t_sample wetToneL = (((((t_a0 * wetWithMakeupL) + (t_a1 * tL_x1p)) + (t_a2 * tL_x2p)) - (t_b1 * tL_y1p)) - (t_b2 * tL_y2p));
			m_toneL_x_16 = tL_x1p;
			m_toneL_x_17 = wetWithMakeupL;
			m_toneL_y_14 = tL_y1p;
			m_toneL_y_15 = wetToneL;
			t_sample tR_x1p = fixdenorm(m_toneR_x_13);
			t_sample tR_x2p = fixdenorm(m_toneR_x_12);
			t_sample tR_y1p = fixdenorm(m_toneR_y_11);
			t_sample tR_y2p = fixdenorm(m_toneR_y_10);
			t_sample wetToneR = (((((t_a0 * wetWithMakeupR) + (t_a1 * tR_x1p)) + (t_a2 * tR_x2p)) - (t_b1 * tR_y1p)) - (t_b2 * tR_y2p));
			m_toneR_x_12 = tR_x1p;
			m_toneR_x_13 = wetWithMakeupR;
			m_toneR_y_10 = tR_y1p;
			m_toneR_y_11 = wetToneR;
			t_sample mix_2903 = (wetWithMakeupL + (toneOn * (wetToneL - wetWithMakeupL)));
			t_sample mix_2904 = (wetWithMakeupR + (toneOn * (wetToneR - wetWithMakeupR)));
			t_sample apL_x1p = fixdenorm(m_toneApL_x_8);
			t_sample apL_x2p = fixdenorm(m_toneApL_x_7);
			t_sample apL_y1p = fixdenorm(m_toneApL_y_6);
			t_sample apL_y2p = fixdenorm(m_toneApL_y_5);
			t_sample dryCompL_2836 = (((((ap_b0 * dryL) + (ap_b1 * apL_x1p)) + (((int)1) * apL_x2p)) - (ap_a1 * apL_y1p)) - (ap_a2 * apL_y2p));
			m_toneApL_x_7 = apL_x1p;
			m_toneApL_x_8 = dryL;
			m_toneApL_y_5 = apL_y1p;
			m_toneApL_y_6 = dryCompL_2836;
			t_sample apR_x1p = fixdenorm(m_toneApR_x_4);
			t_sample apR_x2p = fixdenorm(m_toneApR_x_3);
			t_sample apR_y1p = fixdenorm(m_toneApR_y_2);
			t_sample apR_y2p = fixdenorm(m_toneApR_y_1);
			t_sample dryCompR_2837 = (((((ap_b0 * dryR) + (ap_b1 * apR_x1p)) + (((int)1) * apR_x2p)) - (ap_a1 * apR_y1p)) - (ap_a2 * apR_y2p));
			m_toneApR_x_3 = apR_x1p;
			m_toneApR_x_4 = dryR;
			m_toneApR_y_1 = apR_y1p;
			m_toneApR_y_2 = dryCompR_2837;
			t_sample mix_2905 = (dryL + (toneOn * (dryCompL_2836 - dryL)));
			t_sample mix_2906 = (dryR + (toneOn * (dryCompR_2837 - dryR)));
			t_sample mix_2907 = (mix_2905 + (drywet * (mix_2903 - mix_2905)));
			t_sample mix_2908 = (mix_2906 + (drywet * (mix_2904 - mix_2906)));
			t_sample clamp_2910 = ((mix_2907 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_2907 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_2907));
			t_sample mix_2909 = (mix_2907 + (safeOn * (clamp_2910 - mix_2907)));
			t_sample clamp_2912 = ((mix_2908 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_2908 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_2908));
			t_sample mix_2911 = (mix_2908 + (safeOn * (clamp_2912 - mix_2908)));
			t_sample mix_2913 = (lIn + (bypass * (mix_2909 - lIn)));
			t_sample mix_2914 = (rIn + (bypass * (mix_2911 - rIn)));
			t_sample out3 = ((int)0);
			t_sample out4 = lTrimmed;
			t_sample out1 = mix_2913;
			t_sample out5 = rTrimmed;
			t_sample out2 = mix_2914;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_t_TONEQ(t_param _value) {
		m_t_TONEQ_320 = (_value < 0.70710678118655 ? 0.70710678118655 : (_value > 16 ? 16 : _value));
	};
	inline void set_r_TONEFREQ(t_param _value) {
		m_r_TONEFREQ_321 = (_value < 20 ? 20 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_q_TONEON(t_param _value) {
		m_q_TONEON_322 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_SAFELIMITON(t_param _value) {
		m_p_SAFELIMITON_323 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_BANDSOLO(t_param _value) {
		m_p_BANDSOLO_324 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_DISTON(t_param _value) {
		m_p_DISTON_325 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_TILTPOS(t_param _value) {
		m_p_TILTPOS_326 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_327 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_328 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_329 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_330 = (_value < -24 ? -24 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_331 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_332 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_333 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_334 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_335 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_336 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_337 = (_value < 2 ? 2 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_338 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_339 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_340 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_341 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_342 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_343 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void softclip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_381 = (inl >= ((int)0));
		t_sample iftrue_382 = (inl * lDrivePos);
		t_sample iffalse_383 = (inl * lDriveNeg);
		t_sample lNorm = safediv((cond_381 ? iftrue_382 : iffalse_383), cell);
		int cond_384 = (inr >= ((int)0));
		t_sample iftrue_385 = (inr * rDrivePos);
		t_sample iffalse_386 = (inr * rDriveNeg);
		t_sample rNorm = safediv((cond_384 ? iftrue_385 : iffalse_386), cell);
		t_sample lCubic = (lNorm - (((lNorm * lNorm) * lNorm) * ((t_sample)0.33333333333333)));
		t_sample rCubic = (rNorm - (((rNorm * rNorm) * rNorm) * ((t_sample)0.33333333333333)));
		t_sample lLimited = (((lNorm > 0) ? 1 : ((lNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		t_sample rLimited = (((rNorm > 0) ? 1 : ((rNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		int cond_387 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_387 ? lCubic : lLimited);
		int cond_388 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_388 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_391 = (inl >= ((int)0));
		t_sample iftrue_392 = (inl * lDrivePos);
		t_sample iffalse_393 = (inl * lDriveNeg);
		t_sample lAdj = (cond_391 ? iftrue_392 : iffalse_393);
		int cond_394 = (inr >= ((int)0));
		t_sample iftrue_395 = (inr * rDrivePos);
		t_sample iffalse_396 = (inr * rDriveNeg);
		t_sample rAdj = (cond_394 ? iftrue_395 : iffalse_396);
		int factor = (-((int)1));
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lAdj))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rAdj))))) - ((int)1));
		t_sample v_397 = (l * cell);
		t_sample min_398 = (-cell);
		t_sample lOut = ((v_397 <= min_398) ? min_398 : ((v_397 >= cell) ? cell : v_397));
		t_sample v_399 = (r * cell);
		t_sample min_400 = (-cell);
		t_sample rOut = ((v_399 <= min_400) ? min_400 : ((v_399 >= cell) ? cell : v_399));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_403 = (inl >= ((int)0));
		t_sample iftrue_404 = (inl * lDrivePos);
		t_sample iffalse_405 = (inl * lDriveNeg);
		t_sample lAdj = (cond_403 ? iftrue_404 : iffalse_405);
		int cond_406 = (inr >= ((int)0));
		t_sample iftrue_407 = (inr * rDrivePos);
		t_sample iffalse_408 = (inr * rDriveNeg);
		t_sample rAdj = (cond_406 ? iftrue_407 : iffalse_408);
		t_sample l = ((((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0)) * fabs(lAdj)) * ((t_sample)0.707));
		t_sample r = ((((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0)) * fabs(rAdj)) * ((t_sample)0.707));
		t_sample min_409 = (-cell);
		t_sample lOut = ((l <= min_409) ? min_409 : ((l >= cell) ? cell : l));
		t_sample min_410 = (-cell);
		t_sample rOut = ((r <= min_410) ? min_410 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_413 = (inl >= ((int)0));
		t_sample iftrue_414 = (inl * lDrivePos);
		t_sample iffalse_415 = (inl * lDriveNeg);
		t_sample lAdj = (cond_413 ? iftrue_414 : iffalse_415);
		int cond_416 = (inr >= ((int)0));
		t_sample iftrue_417 = (inr * rDrivePos);
		t_sample iffalse_418 = (inr * rDriveNeg);
		t_sample rAdj = (cond_416 ? iftrue_417 : iffalse_418);
		int signl = ((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0));
		int signr = ((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0));
		t_sample l = (signl * (((int)1) - exp((-fabs(lAdj)))));
		t_sample r = (signr * (((int)1) - exp((-fabs(rAdj)))));
		t_sample min_419 = (-cell);
		t_sample lOut = ((l <= min_419) ? min_419 : ((l >= cell) ? cell : l));
		t_sample min_420 = (-cell);
		t_sample rOut = ((r <= min_420) ? min_420 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_423 = (inl >= ((int)0));
		t_sample v_424 = (inl * lDrivePos);
		t_sample min_425 = (-cell);
		t_sample iftrue_426 = ((v_424 <= min_425) ? min_425 : ((v_424 >= cell) ? cell : v_424));
		t_sample v_427 = (inl * lDriveNeg);
		t_sample min_428 = (-cell);
		t_sample iffalse_429 = ((v_427 <= min_428) ? min_428 : ((v_427 >= cell) ? cell : v_427));
		t_sample l = (cond_423 ? iftrue_426 : iffalse_429);
		int cond_430 = (inr >= ((int)0));
		t_sample v_431 = (inr * rDrivePos);
		t_sample min_432 = (-cell);
		t_sample iftrue_433 = ((v_431 <= min_432) ? min_432 : ((v_431 >= cell) ? cell : v_431));
		t_sample v_434 = (inr * rDriveNeg);
		t_sample min_435 = (-cell);
		t_sample iffalse_436 = ((v_434 <= min_435) ? min_435 : ((v_434 >= cell) ? cell : v_434));
		t_sample r = (cond_430 ? iftrue_433 : iffalse_436);
		t_sample lOut = safediv(tanh(l), tanh(dr));
		t_sample rOut = safediv(tanh(r), tanh(dr));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectH_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample maxa_439 = (inl * lDrivePos);
		t_sample lPositive = ((maxa_439 < ((int)0)) ? ((int)0) : maxa_439);
		t_sample maxa_440 = (inr * rDrivePos);
		t_sample rPositive = ((maxa_440 < ((int)0)) ? ((int)0) : maxa_440);
		t_sample v_441 = (lPositive * ((t_sample)0.5));
		t_sample min_442 = (-cell);
		t_sample l = ((v_441 <= min_442) ? min_442 : ((v_441 >= cell) ? cell : v_441));
		t_sample v_443 = (rPositive * ((t_sample)0.5));
		t_sample min_444 = (-cell);
		t_sample r = ((v_443 <= min_444) ? min_444 : ((v_443 >= cell) ? cell : v_443));
		out1 = l;
		out2 = r;
		
	};
	inline void arctangent_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_447 = (inl >= ((int)0));
		t_sample iftrue_448 = (inl * lDrivePos);
		t_sample iffalse_449 = (inl * lDriveNeg);
		t_sample lAdj = (cond_447 ? iftrue_448 : iffalse_449);
		int cond_450 = (inr >= ((int)0));
		t_sample iftrue_451 = (inr * rDrivePos);
		t_sample iffalse_452 = (inr * rDriveNeg);
		t_sample rAdj = (cond_450 ? iftrue_451 : iffalse_452);
		t_sample l = ((((int)2) * ((t_sample)0.31830988618379)) * atan((lAdj * ((int)2))));
		t_sample r = ((((int)2) * ((t_sample)0.31830988618379)) * atan((rAdj * ((int)2))));
		t_sample lOut = (l * cell);
		t_sample rOut = (r * cell);
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void hardClip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_455 = (inl >= ((int)0));
		t_sample iftrue_456 = (inl * lDrivePos);
		t_sample iffalse_457 = (inl * lDriveNeg);
		t_sample lDriven = (cond_455 ? iftrue_456 : iffalse_457);
		int cond_458 = (inr >= ((int)0));
		t_sample iftrue_459 = (inr * rDrivePos);
		t_sample iffalse_460 = (inr * rDriveNeg);
		t_sample rDriven = (cond_458 ? iftrue_459 : iffalse_460);
		int cond_461 = (lDriven > cell);
		int cond_462 = (lDriven < (-cell));
		t_sample iftrue_463 = (-cell);
		t_sample iffalse_464 = (cond_462 ? iftrue_463 : lDriven);
		t_sample l = (cond_461 ? cell : iffalse_464);
		int cond_465 = (rDriven > cell);
		int cond_466 = (rDriven < (-cell));
		t_sample iftrue_467 = (-cell);
		t_sample iffalse_468 = (cond_466 ? iftrue_467 : rDriven);
		t_sample r = (cond_465 ? cell : iffalse_468);
		out1 = l;
		out2 = r;
		
	};
	inline void bitCrusher_d_d_d(t_sample inl, t_sample inr, t_sample bits, t_sample& out1, t_sample& out2) {
		t_sample steps = (safepow(((int)2), bits) - ((int)1));
		t_sample invSteps = safediv(((int)1), steps);
		t_sample l = (round((inl * steps)) * invSteps);
		t_sample r = (round((inr * steps)) * invSteps);
		out1 = l;
		out2 = r;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 5;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 24; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4", "out5" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_a_DRYWET(value); break;
		case 1: self->set_b_DRIVE(value); break;
		case 2: self->set_c_DC(value); break;
		case 3: self->set_d_MODE(value); break;
		case 4: self->set_e_CEILING(value); break;
		case 5: self->set_f_BYPASS(value); break;
		case 6: self->set_g_BITS(value); break;
		case 7: self->set_h_BITSON(value); break;
		case 8: self->set_i_TILT(value); break;
		case 9: self->set_j_HPF(value); break;
		case 10: self->set_k_INPUT(value); break;
		case 11: self->set_k_LPF(value); break;
		case 12: self->set_l_OUTPUT(value); break;
		case 13: self->set_l_SC(value); break;
		case 14: self->set_m_DOWNSAMPLE(value); break;
		case 15: self->set_n_DOWNSAMPLEON(value); break;
		case 16: self->set_o_BAND(value); break;
		case 17: self->set_p_BANDSOLO(value); break;
		case 18: self->set_p_DISTON(value); break;
		case 19: self->set_p_SAFELIMITON(value); break;
		case 20: self->set_p_TILTPOS(value); break;
		case 21: self->set_q_TONEON(value); break;
		case 22: self->set_r_TONEFREQ(value); break;
		case 23: self->set_t_TONEQ(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_343; break;
		case 1: *value = self->m_b_DRIVE_342; break;
		case 2: *value = self->m_c_DC_341; break;
		case 3: *value = self->m_d_MODE_340; break;
		case 4: *value = self->m_e_CEILING_339; break;
		case 5: *value = self->m_f_BYPASS_338; break;
		case 6: *value = self->m_g_BITS_337; break;
		case 7: *value = self->m_h_BITSON_336; break;
		case 8: *value = self->m_i_TILT_335; break;
		case 9: *value = self->m_j_HPF_334; break;
		case 10: *value = self->m_k_INPUT_331; break;
		case 11: *value = self->m_k_LPF_333; break;
		case 12: *value = self->m_l_OUTPUT_330; break;
		case 13: *value = self->m_l_SC_332; break;
		case 14: *value = self->m_m_DOWNSAMPLE_329; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_328; break;
		case 16: *value = self->m_o_BAND_327; break;
		case 17: *value = self->m_p_BANDSOLO_324; break;
		case 18: *value = self->m_p_DISTON_325; break;
		case 19: *value = self->m_p_SAFELIMITON_323; break;
		case 20: *value = self->m_p_TILTPOS_326; break;
		case 21: *value = self->m_q_TONEON_322; break;
		case 22: *value = self->m_r_TONEFREQ_321; break;
		case 23: *value = self->m_t_TONEQ_320; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(24 * sizeof(ParamInfo));
	self->__commonstate.numparams = 24;
	// initialize parameter 0 ("m_a_DRYWET_343")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_343;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_342")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_342;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_341")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_341;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_340")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_340;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_339")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_339;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_338")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_338;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_337")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_337;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 2;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_336")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_336;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_335")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_335;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_334")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_334;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_331")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_331;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_333")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_333;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_330")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_330;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -24;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_332")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_332;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_329")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_329;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_328")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_328;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_327")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_327;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_p_BANDSOLO_324")
	pi = self->__commonstate.params + 17;
	pi->name = "p_BANDSOLO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_BANDSOLO_324;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_p_DISTON_325")
	pi = self->__commonstate.params + 18;
	pi->name = "p_DISTON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_DISTON_325;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_p_SAFELIMITON_323")
	pi = self->__commonstate.params + 19;
	pi->name = "p_SAFELIMITON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_SAFELIMITON_323;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_p_TILTPOS_326")
	pi = self->__commonstate.params + 20;
	pi->name = "p_TILTPOS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_TILTPOS_326;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_q_TONEON_322")
	pi = self->__commonstate.params + 21;
	pi->name = "q_TONEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_TONEON_322;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_r_TONEFREQ_321")
	pi = self->__commonstate.params + 22;
	pi->name = "r_TONEFREQ";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_r_TONEFREQ_321;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_t_TONEQ_320")
	pi = self->__commonstate.params + 23;
	pi->name = "t_TONEQ";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_t_TONEQ_320;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.70710678118655;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // JCBDistortion::
