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
	DCBlock __m_dcblock_401;
	DCBlock __m_dcblock_423;
	DCBlock __m_dcblock_420;
	DCBlock __m_dcblock_424;
	DCBlock __m_dcblock_402;
	DCBlock __m_dcblock_419;
	int __exception;
	int vectorsize;
	t_sample m_R_u2_y_217;
	t_sample m_R_ap_low_lp1_x_216;
	t_sample m_R_ap_low_lp1_y_215;
	t_sample m_R_u2_y_218;
	t_sample m_R_u1_y_220;
	t_sample m_R_u2_x_219;
	t_sample m_R_u1_y_221;
	t_sample m_R_ap_low_lp1_y_214;
	t_sample m_R_ap_low_hp1_x_210;
	t_sample m_R_ap_low_lp2_y_212;
	t_sample m_R_ap_low_hp2_x_207;
	t_sample m_R_ap_low_hp2_y_206;
	t_sample m_R_ap_low_lp2_x_213;
	t_sample m_R_ap_low_hp1_y_208;
	t_sample m_R_u1_x_222;
	t_sample m_R_ap_low_hp1_y_209;
	t_sample m_R_ap_low_lp2_y_211;
	t_sample m_R_m2_y_223;
	t_sample m_R_m1_y_227;
	t_sample m_R_m2_x_225;
	t_sample m_R_l2_x_237;
	t_sample m_R_l2_y_236;
	t_sample m_R_l2_y_235;
	t_sample m_R_l1_y_238;
	t_sample m_R_l1_x_240;
	t_sample m_R_l1_y_239;
	t_sample m_L_ap2_hp2_y_241;
	t_sample m_R_m2_y_224;
	t_sample m_R_h1_x_234;
	t_sample m_R_h1_y_232;
	t_sample m_R_ap_low_hp2_y_205;
	t_sample m_R_m1_y_226;
	t_sample m_R_h1_y_233;
	t_sample m_R_m1_x_228;
	t_sample m_R_h2_y_230;
	t_sample m_R_h2_y_229;
	t_sample m_R_h2_x_231;
	t_sample m_R_ap1_lp1_x_204;
	t_sample m_R_ap1_lp2_y_200;
	t_sample m_R_ap1_lp1_y_202;
	t_sample m_l1_y_177;
	t_sample m_l2_x_176;
	t_sample m_l2_x_175;
	t_sample m_l1_y_178;
	t_sample m_l1_x_180;
	t_sample m_l1_x_179;
	t_sample m_R_ap2_hp2_y_181;
	t_sample m_R_ap2_hp2_y_182;
	t_sample m_l2_y_174;
	t_sample m_h1_x_172;
	t_sample m_h2_x_167;
	t_sample m_h2_y_166;
	t_sample m_l2_y_173;
	t_sample m_h2_x_168;
	t_sample m_h1_y_170;
	t_sample m_h1_y_169;
	t_sample m_h1_x_171;
	t_sample m_R_ap1_lp1_y_203;
	t_sample m_R_ap2_hp2_x_183;
	t_sample m_R_ap2_hp1_y_185;
	t_sample m_R_ap1_hp1_y_197;
	t_sample m_R_ap1_hp1_y_196;
	t_sample m_R_ap1_hp2_x_195;
	t_sample m_R_ap1_hp1_x_198;
	t_sample m_L_ap2_hp2_y_242;
	t_sample m_R_ap1_lp2_y_199;
	t_sample m_R_ap1_lp2_x_201;
	t_sample m_R_ap2_hp1_y_184;
	t_sample m_R_ap1_hp2_y_194;
	t_sample m_R_ap2_lp1_x_192;
	t_sample m_R_ap2_lp2_y_187;
	t_sample m_R_ap2_hp1_x_186;
	t_sample m_R_ap1_hp2_y_193;
	t_sample m_R_ap2_lp2_y_188;
	t_sample m_R_ap2_lp1_y_190;
	t_sample m_R_ap2_lp2_x_189;
	t_sample m_R_ap2_lp1_y_191;
	t_sample m_L_ap2_hp2_x_243;
	t_sample m_L_ap2_lp2_y_247;
	t_sample m_L_ap2_hp1_y_245;
	t_sample m_L_l2_x_297;
	t_sample m_L_l2_y_296;
	t_sample m_L_l2_y_295;
	t_sample m_L_l1_y_298;
	t_sample m_L_l1_x_300;
	t_sample m_L_l1_y_299;
	t_sample m_p_SAFELIMITON_301;
	t_sample m_p_BANDSOLO_302;
	t_sample m_L_h1_x_294;
	t_sample m_L_h1_y_292;
	t_sample m_L_m1_y_287;
	t_sample m_L_m1_y_286;
	t_sample m_L_h1_y_293;
	t_sample m_L_m1_x_288;
	t_sample m_L_h2_y_290;
	t_sample m_L_h2_y_289;
	t_sample m_L_h2_x_291;
	t_sample m_L_m2_x_285;
	t_sample m_p_DISTON_303;
	t_sample m_o_BAND_305;
	t_sample m_e_CEILING_317;
	t_sample m_f_BYPASS_316;
	t_sample m_g_BITS_315;
	t_sample m_d_MODE_318;
	t_sample m_b_DRIVE_320;
	t_sample m_c_DC_319;
	t_sample m_a_DRYWET_321;
	t_sample m_p_TILTPOS_304;
	t_sample m_h_BITSON_314;
	t_sample m_j_HPF_312;
	t_sample m_m_DOWNSAMPLE_307;
	t_sample m_n_DOWNSAMPLEON_306;
	t_sample m_i_TILT_313;
	t_sample m_l_OUTPUT_308;
	t_sample m_l_SC_310;
	t_sample m_k_INPUT_309;
	t_sample m_k_LPF_311;
	t_sample m_L_ap2_hp1_y_244;
	t_sample m_L_m2_y_284;
	t_sample m_L_u1_x_282;
	t_sample m_L_ap1_hp1_y_257;
	t_sample m_L_ap1_hp1_y_256;
	t_sample m_L_ap1_hp2_x_255;
	t_sample m_L_ap1_hp1_x_258;
	t_sample m_L_ap1_lp2_y_260;
	t_sample m_L_ap1_lp2_y_259;
	t_sample m_L_ap1_lp2_x_261;
	t_sample m_L_ap1_lp1_y_262;
	t_sample m_L_ap1_hp2_y_254;
	t_sample m_L_ap2_lp1_x_252;
	t_sample m_h2_y_165;
	t_sample m_L_ap2_hp1_x_246;
	t_sample m_L_ap1_hp2_y_253;
	t_sample m_L_ap2_lp2_y_248;
	t_sample m_L_ap2_lp1_y_250;
	t_sample m_L_ap2_lp2_x_249;
	t_sample m_L_ap2_lp1_y_251;
	t_sample m_L_m2_y_283;
	t_sample m_L_ap1_lp1_y_263;
	t_sample m_L_ap_low_hp2_y_265;
	t_sample m_L_u2_y_277;
	t_sample m_L_ap_low_lp1_x_276;
	t_sample m_L_ap_low_lp1_y_275;
	t_sample m_L_u2_y_278;
	t_sample m_L_u1_y_280;
	t_sample m_L_u2_x_279;
	t_sample m_L_u1_y_281;
	t_sample m_L_ap1_lp1_x_264;
	t_sample m_L_ap_low_lp1_y_274;
	t_sample m_L_ap_low_lp2_y_272;
	t_sample m_L_ap_low_hp2_x_267;
	t_sample m_L_ap_low_hp2_y_266;
	t_sample m_L_ap_low_lp2_x_273;
	t_sample m_L_ap_low_hp1_y_268;
	t_sample m_L_ap_low_hp1_x_270;
	t_sample m_L_ap_low_hp1_y_269;
	t_sample m_L_ap_low_lp2_y_271;
	t_sample m_m1_x_164;
	t_sample m_m1_x_163;
	t_sample m_m1_y_162;
	t_sample m_postTiltLsR_53;
	t_sample m_postTiltLsR_52;
	t_sample m_postTiltHsL_51;
	t_sample m_postTiltHsL_50;
	t_sample m_postTiltLsR_54;
	t_sample m_postTiltLsL_56;
	t_sample m_postTiltLsR_55;
	t_sample m_postTiltLsL_57;
	t_sample m_postTiltLsL_58;
	t_sample m_postTiltHsL_49;
	t_sample m_postTiltHsR_47;
	t_sample m_R_l1_x_42;
	t_sample m_L_l2_x_41;
	t_sample m_postTiltHsL_48;
	t_sample m_L_l1_x_43;
	t_sample m_postTiltHsR_45;
	t_sample m_postTiltHsR_44;
	t_sample m_postTiltHsR_46;
	t_sample m_R_l2_x_40;
	t_sample m_postTiltLsL_59;
	t_sample m_tiltHsR_61;
	t_sample m_tiltLsL_74;
	t_sample m_tiltLsL_73;
	t_sample m_tiltLsR_72;
	t_sample m_tiltLsR_71;
	t_sample m_tiltLsL_75;
	t_sample m_dsEnablePrev_77;
	t_sample m_tiltLsL_76;
	t_sample m_dsTrigPrev_78;
	t_sample m_hTiltPos_60;
	t_sample m_tiltLsR_70;
	t_sample m_tiltHsL_68;
	t_sample m_tiltHsR_63;
	t_sample m_tiltHsR_62;
	t_sample m_tiltLsR_69;
	t_sample m_tiltHsR_64;
	t_sample m_tiltHsL_66;
	t_sample m_tiltHsL_65;
	t_sample m_tiltHsL_67;
	t_sample m_dsPhase_79;
	t_sample m_L_h1_x_39;
	t_sample m_L_h2_x_37;
	t_sample m_R_ap1_hp2_x_12;
	t_sample m_L_ap2_lp1_x_11;
	t_sample m_R_ap2_lp1_x_10;
	t_sample m_L_ap2_lp2_x_9;
	t_sample m_L_ap1_hp2_x_13;
	t_sample m_L_ap1_hp1_x_15;
	t_sample m_R_ap1_hp1_x_14;
	t_sample m_R_ap1_lp2_x_16;
	t_sample m_L_ap1_lp2_x_17;
	t_sample m_R_ap2_lp2_x_8;
	t_sample m_R_ap2_hp1_x_6;
	t_sample m_hSafeLimitOn_1;
	t_sample samplerate;
	t_sample m_L_ap2_hp1_x_7;
	t_sample m_hBandSolo_2;
	t_sample m_R_ap2_hp2_x_4;
	t_sample m_hDistOn_3;
	t_sample m_L_ap2_hp2_x_5;
	t_sample m_R_h1_x_38;
	t_sample m_R_ap1_lp1_x_18;
	t_sample m_R_ap_low_hp2_x_20;
	t_sample m_R_m2_x_32;
	t_sample m_L_u1_x_31;
	t_sample m_R_u1_x_30;
	t_sample m_L_m2_x_33;
	t_sample m_L_m1_x_35;
	t_sample m_R_m1_x_34;
	t_sample m_R_h2_x_36;
	t_sample m_L_ap1_lp1_x_19;
	t_sample m_L_u2_x_29;
	t_sample m_L_ap_low_lp1_x_27;
	t_sample m_R_ap_low_hp1_x_22;
	t_sample m_L_ap_low_hp2_x_21;
	t_sample m_R_u2_x_28;
	t_sample m_L_ap_low_hp1_x_23;
	t_sample m_L_ap_low_lp2_x_25;
	t_sample m_R_ap_low_lp2_x_24;
	t_sample m_R_ap_low_lp1_x_26;
	t_sample __m_latch_427;
	t_sample m_dsPhasor_80;
	t_sample m_lpfFreqHistory_82;
	t_sample m_ap_low_hp2_x_136;
	t_sample m_ap_low_hp2_x_135;
	t_sample m_ap_low_hp2_y_134;
	t_sample m_ap_low_hp2_y_133;
	t_sample m_ap_low_hp1_y_137;
	t_sample m_ap_low_hp1_x_139;
	t_sample m_ap_low_hp1_y_138;
	t_sample m_ap_low_hp1_x_140;
	t_sample m_ap_low_lp2_y_141;
	t_sample m_ap1_lp1_x_132;
	t_sample m_ap1_lp1_y_130;
	t_sample m_ap1_lp2_y_125;
	t_sample m_ap1_hp1_x_124;
	t_sample m_ap1_lp1_x_131;
	t_sample m_ap1_lp2_y_126;
	t_sample m_ap1_lp2_x_128;
	t_sample m_ap1_lp2_x_127;
	t_sample m_ap1_lp1_y_129;
	t_sample m_ap1_hp1_x_123;
	t_sample m_ap_low_lp2_y_142;
	t_sample m_ap_low_lp2_x_144;
	t_sample m_m2_y_157;
	t_sample m_u1_x_156;
	t_sample m_u1_x_155;
	t_sample m_u1_y_154;
	t_sample m_m2_y_158;
	t_sample m_m2_x_160;
	t_sample m_m2_x_159;
	t_sample m_m1_y_161;
	t_sample m_ap_low_lp2_x_143;
	t_sample m_u1_y_153;
	t_sample m_u2_x_151;
	t_sample m_ap_low_lp1_y_146;
	t_sample m_ap_low_lp1_y_145;
	t_sample m_u2_x_152;
	t_sample m_ap_low_lp1_x_147;
	t_sample m_u2_y_149;
	t_sample m_ap_low_lp1_x_148;
	t_sample m_u2_y_150;
	t_sample m_scEnableHistory_81;
	t_sample m_ap1_hp1_y_122;
	t_sample m_ap1_hp2_x_120;
	t_sample m_hBitson_95;
	t_sample m_hTilt_94;
	t_sample m_hInput_93;
	t_sample m_hOutput_92;
	t_sample m_hBits_96;
	t_sample m_hDc_98;
	t_sample m_hDrywet_97;
	t_sample m_hDrive_99;
	t_sample m_hBand_100;
	t_sample m_hMode_91;
	t_sample m_hDownsampleOn_89;
	t_sample m_lpfR_z_84;
	t_sample m_hpfFreqHistory_83;
	t_sample m_hDownsample_90;
	t_sample m_lpfL_z_85;
	t_sample m_hpfL_z_87;
	t_sample m_hpfR_z_86;
	t_sample m_hBypass_88;
	t_sample m_ap1_hp1_y_121;
	t_sample m_ap2_hp2_y_101;
	t_sample m_ap2_hp2_x_103;
	t_sample m_ap2_lp1_x_115;
	t_sample m_ap2_lp1_y_114;
	t_sample m_ap2_lp1_y_113;
	t_sample m_ap2_lp1_x_116;
	t_sample m_ap1_hp2_y_118;
	t_sample m_ap1_hp2_y_117;
	t_sample m_ap1_hp2_x_119;
	t_sample m_ap2_hp2_y_102;
	t_sample m_ap2_lp2_x_112;
	t_sample m_ap2_lp2_y_110;
	t_sample m_ap2_hp1_y_105;
	t_sample m_ap2_hp2_x_104;
	t_sample m_ap2_lp2_x_111;
	t_sample m_ap2_hp1_y_106;
	t_sample m_ap2_hp1_x_108;
	t_sample m_ap2_hp1_x_107;
	t_sample m_ap2_lp2_y_109;
	t_sample __m_latch_428;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_hSafeLimitOn_1 = ((int)0);
		m_hBandSolo_2 = ((int)0);
		m_hDistOn_3 = ((int)1);
		m_R_ap2_hp2_x_4 = ((int)0);
		m_L_ap2_hp2_x_5 = ((int)0);
		m_R_ap2_hp1_x_6 = ((int)0);
		m_L_ap2_hp1_x_7 = ((int)0);
		m_R_ap2_lp2_x_8 = ((int)0);
		m_L_ap2_lp2_x_9 = ((int)0);
		m_R_ap2_lp1_x_10 = ((int)0);
		m_L_ap2_lp1_x_11 = ((int)0);
		m_R_ap1_hp2_x_12 = ((int)0);
		m_L_ap1_hp2_x_13 = ((int)0);
		m_R_ap1_hp1_x_14 = ((int)0);
		m_L_ap1_hp1_x_15 = ((int)0);
		m_R_ap1_lp2_x_16 = ((int)0);
		m_L_ap1_lp2_x_17 = ((int)0);
		m_R_ap1_lp1_x_18 = ((int)0);
		m_L_ap1_lp1_x_19 = ((int)0);
		m_R_ap_low_hp2_x_20 = ((int)0);
		m_L_ap_low_hp2_x_21 = ((int)0);
		m_R_ap_low_hp1_x_22 = ((int)0);
		m_L_ap_low_hp1_x_23 = ((int)0);
		m_R_ap_low_lp2_x_24 = ((int)0);
		m_L_ap_low_lp2_x_25 = ((int)0);
		m_R_ap_low_lp1_x_26 = ((int)0);
		m_L_ap_low_lp1_x_27 = ((int)0);
		m_R_u2_x_28 = ((int)0);
		m_L_u2_x_29 = ((int)0);
		m_R_u1_x_30 = ((int)0);
		m_L_u1_x_31 = ((int)0);
		m_R_m2_x_32 = ((int)0);
		m_L_m2_x_33 = ((int)0);
		m_R_m1_x_34 = ((int)0);
		m_L_m1_x_35 = ((int)0);
		m_R_h2_x_36 = ((int)0);
		m_L_h2_x_37 = ((int)0);
		m_R_h1_x_38 = ((int)0);
		m_L_h1_x_39 = ((int)0);
		m_R_l2_x_40 = ((int)0);
		m_L_l2_x_41 = ((int)0);
		m_R_l1_x_42 = ((int)0);
		m_L_l1_x_43 = ((int)0);
		m_postTiltHsR_44 = ((int)0);
		m_postTiltHsR_45 = ((int)0);
		m_postTiltHsR_46 = ((int)0);
		m_postTiltHsR_47 = ((int)0);
		m_postTiltHsL_48 = ((int)0);
		m_postTiltHsL_49 = ((int)0);
		m_postTiltHsL_50 = ((int)0);
		m_postTiltHsL_51 = ((int)0);
		m_postTiltLsR_52 = ((int)0);
		m_postTiltLsR_53 = ((int)0);
		m_postTiltLsR_54 = ((int)0);
		m_postTiltLsR_55 = ((int)0);
		m_postTiltLsL_56 = ((int)0);
		m_postTiltLsL_57 = ((int)0);
		m_postTiltLsL_58 = ((int)0);
		m_postTiltLsL_59 = ((int)0);
		m_hTiltPos_60 = ((int)0);
		m_tiltHsR_61 = ((int)0);
		m_tiltHsR_62 = ((int)0);
		m_tiltHsR_63 = ((int)0);
		m_tiltHsR_64 = ((int)0);
		m_tiltHsL_65 = ((int)0);
		m_tiltHsL_66 = ((int)0);
		m_tiltHsL_67 = ((int)0);
		m_tiltHsL_68 = ((int)0);
		m_tiltLsR_69 = ((int)0);
		m_tiltLsR_70 = ((int)0);
		m_tiltLsR_71 = ((int)0);
		m_tiltLsR_72 = ((int)0);
		m_tiltLsL_73 = ((int)0);
		m_tiltLsL_74 = ((int)0);
		m_tiltLsL_75 = ((int)0);
		m_tiltLsL_76 = ((int)0);
		m_dsEnablePrev_77 = ((int)0);
		m_dsTrigPrev_78 = ((int)0);
		m_dsPhase_79 = ((int)0);
		m_dsPhasor_80 = ((int)0);
		m_scEnableHistory_81 = ((int)0);
		m_lpfFreqHistory_82 = ((int)0);
		m_hpfFreqHistory_83 = ((int)0);
		m_lpfR_z_84 = ((int)0);
		m_lpfL_z_85 = ((int)0);
		m_hpfR_z_86 = ((int)0);
		m_hpfL_z_87 = ((int)0);
		m_hBypass_88 = ((int)0);
		m_hDownsampleOn_89 = ((int)0);
		m_hDownsample_90 = ((int)0);
		m_hMode_91 = ((int)0);
		m_hOutput_92 = ((int)0);
		m_hInput_93 = ((int)0);
		m_hTilt_94 = ((int)0);
		m_hBitson_95 = ((int)0);
		m_hBits_96 = ((int)0);
		m_hDrywet_97 = ((int)0);
		m_hDc_98 = ((int)0);
		m_hDrive_99 = ((int)0);
		m_hBand_100 = ((int)1);
		m_ap2_hp2_y_101 = ((int)0);
		m_ap2_hp2_y_102 = ((int)0);
		m_ap2_hp2_x_103 = ((int)0);
		m_ap2_hp2_x_104 = ((int)0);
		m_ap2_hp1_y_105 = ((int)0);
		m_ap2_hp1_y_106 = ((int)0);
		m_ap2_hp1_x_107 = ((int)0);
		m_ap2_hp1_x_108 = ((int)0);
		m_ap2_lp2_y_109 = ((int)0);
		m_ap2_lp2_y_110 = ((int)0);
		m_ap2_lp2_x_111 = ((int)0);
		m_ap2_lp2_x_112 = ((int)0);
		m_ap2_lp1_y_113 = ((int)0);
		m_ap2_lp1_y_114 = ((int)0);
		m_ap2_lp1_x_115 = ((int)0);
		m_ap2_lp1_x_116 = ((int)0);
		m_ap1_hp2_y_117 = ((int)0);
		m_ap1_hp2_y_118 = ((int)0);
		m_ap1_hp2_x_119 = ((int)0);
		m_ap1_hp2_x_120 = ((int)0);
		m_ap1_hp1_y_121 = ((int)0);
		m_ap1_hp1_y_122 = ((int)0);
		m_ap1_hp1_x_123 = ((int)0);
		m_ap1_hp1_x_124 = ((int)0);
		m_ap1_lp2_y_125 = ((int)0);
		m_ap1_lp2_y_126 = ((int)0);
		m_ap1_lp2_x_127 = ((int)0);
		m_ap1_lp2_x_128 = ((int)0);
		m_ap1_lp1_y_129 = ((int)0);
		m_ap1_lp1_y_130 = ((int)0);
		m_ap1_lp1_x_131 = ((int)0);
		m_ap1_lp1_x_132 = ((int)0);
		m_ap_low_hp2_y_133 = ((int)0);
		m_ap_low_hp2_y_134 = ((int)0);
		m_ap_low_hp2_x_135 = ((int)0);
		m_ap_low_hp2_x_136 = ((int)0);
		m_ap_low_hp1_y_137 = ((int)0);
		m_ap_low_hp1_y_138 = ((int)0);
		m_ap_low_hp1_x_139 = ((int)0);
		m_ap_low_hp1_x_140 = ((int)0);
		m_ap_low_lp2_y_141 = ((int)0);
		m_ap_low_lp2_y_142 = ((int)0);
		m_ap_low_lp2_x_143 = ((int)0);
		m_ap_low_lp2_x_144 = ((int)0);
		m_ap_low_lp1_y_145 = ((int)0);
		m_ap_low_lp1_y_146 = ((int)0);
		m_ap_low_lp1_x_147 = ((int)0);
		m_ap_low_lp1_x_148 = ((int)0);
		m_u2_y_149 = ((int)0);
		m_u2_y_150 = ((int)0);
		m_u2_x_151 = ((int)0);
		m_u2_x_152 = ((int)0);
		m_u1_y_153 = ((int)0);
		m_u1_y_154 = ((int)0);
		m_u1_x_155 = ((int)0);
		m_u1_x_156 = ((int)0);
		m_m2_y_157 = ((int)0);
		m_m2_y_158 = ((int)0);
		m_m2_x_159 = ((int)0);
		m_m2_x_160 = ((int)0);
		m_m1_y_161 = ((int)0);
		m_m1_y_162 = ((int)0);
		m_m1_x_163 = ((int)0);
		m_m1_x_164 = ((int)0);
		m_h2_y_165 = ((int)0);
		m_h2_y_166 = ((int)0);
		m_h2_x_167 = ((int)0);
		m_h2_x_168 = ((int)0);
		m_h1_y_169 = ((int)0);
		m_h1_y_170 = ((int)0);
		m_h1_x_171 = ((int)0);
		m_h1_x_172 = ((int)0);
		m_l2_y_173 = ((int)0);
		m_l2_y_174 = ((int)0);
		m_l2_x_175 = ((int)0);
		m_l2_x_176 = ((int)0);
		m_l1_y_177 = ((int)0);
		m_l1_y_178 = ((int)0);
		m_l1_x_179 = ((int)0);
		m_l1_x_180 = ((int)0);
		m_R_ap2_hp2_y_181 = ((int)0);
		m_R_ap2_hp2_y_182 = ((int)0);
		m_R_ap2_hp2_x_183 = ((int)0);
		m_R_ap2_hp1_y_184 = ((int)0);
		m_R_ap2_hp1_y_185 = ((int)0);
		m_R_ap2_hp1_x_186 = ((int)0);
		m_R_ap2_lp2_y_187 = ((int)0);
		m_R_ap2_lp2_y_188 = ((int)0);
		m_R_ap2_lp2_x_189 = ((int)0);
		m_R_ap2_lp1_y_190 = ((int)0);
		m_R_ap2_lp1_y_191 = ((int)0);
		m_R_ap2_lp1_x_192 = ((int)0);
		m_R_ap1_hp2_y_193 = ((int)0);
		m_R_ap1_hp2_y_194 = ((int)0);
		m_R_ap1_hp2_x_195 = ((int)0);
		m_R_ap1_hp1_y_196 = ((int)0);
		m_R_ap1_hp1_y_197 = ((int)0);
		m_R_ap1_hp1_x_198 = ((int)0);
		m_R_ap1_lp2_y_199 = ((int)0);
		m_R_ap1_lp2_y_200 = ((int)0);
		m_R_ap1_lp2_x_201 = ((int)0);
		m_R_ap1_lp1_y_202 = ((int)0);
		m_R_ap1_lp1_y_203 = ((int)0);
		m_R_ap1_lp1_x_204 = ((int)0);
		m_R_ap_low_hp2_y_205 = ((int)0);
		m_R_ap_low_hp2_y_206 = ((int)0);
		m_R_ap_low_hp2_x_207 = ((int)0);
		m_R_ap_low_hp1_y_208 = ((int)0);
		m_R_ap_low_hp1_y_209 = ((int)0);
		m_R_ap_low_hp1_x_210 = ((int)0);
		m_R_ap_low_lp2_y_211 = ((int)0);
		m_R_ap_low_lp2_y_212 = ((int)0);
		m_R_ap_low_lp2_x_213 = ((int)0);
		m_R_ap_low_lp1_y_214 = ((int)0);
		m_R_ap_low_lp1_y_215 = ((int)0);
		m_R_ap_low_lp1_x_216 = ((int)0);
		m_R_u2_y_217 = ((int)0);
		m_R_u2_y_218 = ((int)0);
		m_R_u2_x_219 = ((int)0);
		m_R_u1_y_220 = ((int)0);
		m_R_u1_y_221 = ((int)0);
		m_R_u1_x_222 = ((int)0);
		m_R_m2_y_223 = ((int)0);
		m_R_m2_y_224 = ((int)0);
		m_R_m2_x_225 = ((int)0);
		m_R_m1_y_226 = ((int)0);
		m_R_m1_y_227 = ((int)0);
		m_R_m1_x_228 = ((int)0);
		m_R_h2_y_229 = ((int)0);
		m_R_h2_y_230 = ((int)0);
		m_R_h2_x_231 = ((int)0);
		m_R_h1_y_232 = ((int)0);
		m_R_h1_y_233 = ((int)0);
		m_R_h1_x_234 = ((int)0);
		m_R_l2_y_235 = ((int)0);
		m_R_l2_y_236 = ((int)0);
		m_R_l2_x_237 = ((int)0);
		m_R_l1_y_238 = ((int)0);
		m_R_l1_y_239 = ((int)0);
		m_R_l1_x_240 = ((int)0);
		m_L_ap2_hp2_y_241 = ((int)0);
		m_L_ap2_hp2_y_242 = ((int)0);
		m_L_ap2_hp2_x_243 = ((int)0);
		m_L_ap2_hp1_y_244 = ((int)0);
		m_L_ap2_hp1_y_245 = ((int)0);
		m_L_ap2_hp1_x_246 = ((int)0);
		m_L_ap2_lp2_y_247 = ((int)0);
		m_L_ap2_lp2_y_248 = ((int)0);
		m_L_ap2_lp2_x_249 = ((int)0);
		m_L_ap2_lp1_y_250 = ((int)0);
		m_L_ap2_lp1_y_251 = ((int)0);
		m_L_ap2_lp1_x_252 = ((int)0);
		m_L_ap1_hp2_y_253 = ((int)0);
		m_L_ap1_hp2_y_254 = ((int)0);
		m_L_ap1_hp2_x_255 = ((int)0);
		m_L_ap1_hp1_y_256 = ((int)0);
		m_L_ap1_hp1_y_257 = ((int)0);
		m_L_ap1_hp1_x_258 = ((int)0);
		m_L_ap1_lp2_y_259 = ((int)0);
		m_L_ap1_lp2_y_260 = ((int)0);
		m_L_ap1_lp2_x_261 = ((int)0);
		m_L_ap1_lp1_y_262 = ((int)0);
		m_L_ap1_lp1_y_263 = ((int)0);
		m_L_ap1_lp1_x_264 = ((int)0);
		m_L_ap_low_hp2_y_265 = ((int)0);
		m_L_ap_low_hp2_y_266 = ((int)0);
		m_L_ap_low_hp2_x_267 = ((int)0);
		m_L_ap_low_hp1_y_268 = ((int)0);
		m_L_ap_low_hp1_y_269 = ((int)0);
		m_L_ap_low_hp1_x_270 = ((int)0);
		m_L_ap_low_lp2_y_271 = ((int)0);
		m_L_ap_low_lp2_y_272 = ((int)0);
		m_L_ap_low_lp2_x_273 = ((int)0);
		m_L_ap_low_lp1_y_274 = ((int)0);
		m_L_ap_low_lp1_y_275 = ((int)0);
		m_L_ap_low_lp1_x_276 = ((int)0);
		m_L_u2_y_277 = ((int)0);
		m_L_u2_y_278 = ((int)0);
		m_L_u2_x_279 = ((int)0);
		m_L_u1_y_280 = ((int)0);
		m_L_u1_y_281 = ((int)0);
		m_L_u1_x_282 = ((int)0);
		m_L_m2_y_283 = ((int)0);
		m_L_m2_y_284 = ((int)0);
		m_L_m2_x_285 = ((int)0);
		m_L_m1_y_286 = ((int)0);
		m_L_m1_y_287 = ((int)0);
		m_L_m1_x_288 = ((int)0);
		m_L_h2_y_289 = ((int)0);
		m_L_h2_y_290 = ((int)0);
		m_L_h2_x_291 = ((int)0);
		m_L_h1_y_292 = ((int)0);
		m_L_h1_y_293 = ((int)0);
		m_L_h1_x_294 = ((int)0);
		m_L_l2_y_295 = ((int)0);
		m_L_l2_y_296 = ((int)0);
		m_L_l2_x_297 = ((int)0);
		m_L_l1_y_298 = ((int)0);
		m_L_l1_y_299 = ((int)0);
		m_L_l1_x_300 = ((int)0);
		m_p_SAFELIMITON_301 = 0;
		m_p_BANDSOLO_302 = 0;
		m_p_DISTON_303 = 1;
		m_p_TILTPOS_304 = 0;
		m_o_BAND_305 = 1;
		m_n_DOWNSAMPLEON_306 = 0;
		m_m_DOWNSAMPLE_307 = 0;
		m_l_OUTPUT_308 = 0;
		m_k_INPUT_309 = 0;
		m_l_SC_310 = 0;
		m_k_LPF_311 = 5000;
		m_j_HPF_312 = 250;
		m_i_TILT_313 = 0;
		m_h_BITSON_314 = 0;
		m_g_BITS_315 = 16;
		m_f_BYPASS_316 = 0;
		m_e_CEILING_317 = 0;
		m_d_MODE_318 = 0;
		m_c_DC_319 = 0;
		m_b_DRIVE_320 = 1;
		m_a_DRYWET_321 = 1;
		__m_dcblock_401.reset();
		__m_dcblock_402.reset();
		__m_dcblock_419.reset();
		__m_dcblock_420.reset();
		__m_dcblock_423.reset();
		__m_dcblock_424.reset();
		__m_latch_427 = 0;
		__m_latch_428 = 0;
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
		t_sample ceiling = dbtoa(m_e_CEILING_317);
		int L_sr = samplerate;
		t_sample minb_322 = (((t_sample)0.45) * L_sr);
		t_sample minb_324 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_327 = (((t_sample)0.45) * R_sr);
		t_sample minb_329 = (((t_sample)0.45) * R_sr);
		int L_sr_8740 = samplerate;
		t_sample minb_338 = (((t_sample)0.45) * L_sr_8740);
		t_sample minb_340 = (((t_sample)0.45) * L_sr_8740);
		int R_sr_8783 = samplerate;
		t_sample minb_343 = (((t_sample)0.45) * R_sr_8783);
		t_sample minb_345 = (((t_sample)0.45) * R_sr_8783);
		t_sample omega = safediv(((t_sample)6283.1853071796), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample cos2 = ((cs * cs) - (sn * sn));
		t_sample sin2 = ((((int)2) * sn) * cs);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_99 = ((m_hDrive_99 * ((t_sample)0.999)) + (m_b_DRIVE_320 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_99;
			m_hDc_98 = ((m_hDc_98 * ((t_sample)0.999)) + (m_c_DC_319 * ((t_sample)0.001)));
			t_sample dc = m_hDc_98;
			m_hDrywet_97 = ((m_hDrywet_97 * ((t_sample)0.999)) + (m_a_DRYWET_321 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_97;
			m_hBits_96 = ((m_hBits_96 * ((t_sample)0.999)) + (m_g_BITS_315 * ((t_sample)0.001)));
			t_sample bits = m_hBits_96;
			m_hBitson_95 = ((m_hBitson_95 * ((t_sample)0.999)) + (m_h_BITSON_314 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_95;
			m_hTilt_94 = ((m_hTilt_94 * ((t_sample)0.999)) + (m_i_TILT_313 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_94;
			m_hInput_93 = ((m_hInput_93 * ((t_sample)0.999)) + (m_k_INPUT_309 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_93;
			m_hOutput_92 = ((m_hOutput_92 * ((t_sample)0.999)) + (m_l_OUTPUT_308 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_92;
			m_hBand_100 = ((m_hBand_100 * ((t_sample)0.999)) + (m_o_BAND_305 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_100;
			m_hMode_91 = ((m_hMode_91 * ((t_sample)0.99)) + (m_d_MODE_318 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_91;
			m_hDownsample_90 = ((m_hDownsample_90 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_307 * ((t_sample)0.001)));
			m_hDownsampleOn_89 = ((m_hDownsampleOn_89 * ((t_sample)0.9)) + (m_n_DOWNSAMPLEON_306 * ((t_sample)0.1)));
			t_sample downsampleOn = m_hDownsampleOn_89;
			m_hBypass_88 = ((m_hBypass_88 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_316) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_88;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_83 * ((t_sample)0.999)) + (m_j_HPF_312 * ((t_sample)0.001)));
			m_hpfFreqHistory_83 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_82 * ((t_sample)0.999)) + (m_k_LPF_311 * ((t_sample)0.001)));
			m_lpfFreqHistory_82 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_81 * ((t_sample)0.999)) + (m_l_SC_310 * ((t_sample)0.001)));
			m_scEnableHistory_81 = fixdenorm(smoothScEnable);
			m_hTiltPos_60 = ((m_hTiltPos_60 * ((t_sample)0.999)) + (m_p_TILTPOS_304 * ((t_sample)0.001)));
			t_sample wPost = ((m_hTiltPos_60 <= ((int)0)) ? ((int)0) : ((m_hTiltPos_60 >= ((int)1)) ? ((int)1) : m_hTiltPos_60));
			m_hDistOn_3 = ((m_hDistOn_3 * ((t_sample)0.999)) + (m_p_DISTON_303 * ((t_sample)0.001)));
			t_sample wDist = ((m_hDistOn_3 <= ((int)0)) ? ((int)0) : ((m_hDistOn_3 >= ((int)1)) ? ((int)1) : m_hDistOn_3));
			m_hBandSolo_2 = ((m_hBandSolo_2 * ((t_sample)0.999)) + (m_p_BANDSOLO_302 * ((t_sample)0.001)));
			t_sample wBandSolo = ((m_hBandSolo_2 <= ((int)0)) ? ((int)0) : ((m_hBandSolo_2 >= ((int)1)) ? ((int)1) : m_hBandSolo_2));
			m_hSafeLimitOn_1 = ((m_hSafeLimitOn_1 * ((t_sample)0.999)) + (m_p_SAFELIMITON_301 * ((t_sample)0.001)));
			t_sample safeOn = ((m_hSafeLimitOn_1 <= ((int)0)) ? ((int)0) : ((m_hSafeLimitOn_1 >= ((int)1)) ? ((int)1) : m_hSafeLimitOn_1));
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_323 = ((minb_322 < L_loF) ? minb_322 : L_loF);
			t_sample L_loF_8727 = ((((int)10) < maxb_323) ? maxb_323 : ((int)10));
			t_sample maxb_325 = ((minb_324 < L_hiF) ? minb_324 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_325) ? maxb_325 : ((int)10));
			t_sample maxb_326 = (L_loF_8727 + ((int)1));
			t_sample L_hiF_8728 = ((L_hiFr < maxb_326) ? maxb_326 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_8727), L_sr);
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
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_8728), L_sr);
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
			t_sample L_l1_x1p = m_L_l1_x_43;
			t_sample L_l1_x2p = m_L_l1_x_300;
			t_sample L_l1_y1p = m_L_l1_y_299;
			t_sample L_l1_y2p = m_L_l1_y_298;
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_300 = L_l1_x1p;
			m_L_l1_x_43 = L_x;
			m_L_l1_y_298 = L_l1_y1p;
			m_L_l1_y_299 = L_low_s1;
			t_sample L_l2_x1p = m_L_l2_x_41;
			t_sample L_l2_x2p = m_L_l2_x_297;
			t_sample L_l2_y1p = m_L_l2_y_296;
			t_sample L_l2_y2p = m_L_l2_y_295;
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_297 = L_l2_x1p;
			m_L_l2_x_41 = L_low_s1;
			m_L_l2_y_295 = L_l2_y1p;
			m_L_l2_y_296 = L_low_raw;
			t_sample L_h1_x1p = m_L_h1_x_39;
			t_sample L_h1_x2p = m_L_h1_x_294;
			t_sample L_h1_y1p = m_L_h1_y_293;
			t_sample L_h1_y2p = m_L_h1_y_292;
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_294 = L_h1_x1p;
			m_L_h1_x_39 = L_x;
			m_L_h1_y_292 = L_h1_y1p;
			m_L_h1_y_293 = L_rest_s1;
			t_sample L_h2_x1p = m_L_h2_x_37;
			t_sample L_h2_x2p = m_L_h2_x_291;
			t_sample L_h2_y1p = m_L_h2_y_290;
			t_sample L_h2_y2p = m_L_h2_y_289;
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_291 = L_h2_x1p;
			m_L_h2_x_37 = L_rest_s1;
			m_L_h2_y_289 = L_h2_y1p;
			m_L_h2_y_290 = L_rest;
			t_sample L_ap_low_lp1_x1p = m_L_ap_low_lp1_x_27;
			t_sample L_ap_low_lp1_x2p = m_L_ap_low_lp1_x_276;
			t_sample L_ap_low_lp1_y1p = m_L_ap_low_lp1_y_275;
			t_sample L_ap_low_lp1_y2p = m_L_ap_low_lp1_y_274;
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_276 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_27 = L_low_raw;
			m_L_ap_low_lp1_y_274 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_275 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = m_L_ap_low_lp2_x_25;
			t_sample L_ap_low_lp2_x2p = m_L_ap_low_lp2_x_273;
			t_sample L_ap_low_lp2_y1p = m_L_ap_low_lp2_y_272;
			t_sample L_ap_low_lp2_y2p = m_L_ap_low_lp2_y_271;
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_273 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_25 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_271 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_272 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = m_L_ap_low_hp1_x_23;
			t_sample L_ap_low_hp1_x2p = m_L_ap_low_hp1_x_270;
			t_sample L_ap_low_hp1_y1p = m_L_ap_low_hp1_y_269;
			t_sample L_ap_low_hp1_y2p = m_L_ap_low_hp1_y_268;
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_270 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_23 = L_low_raw;
			m_L_ap_low_hp1_y_268 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_269 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = m_L_ap_low_hp2_x_21;
			t_sample L_ap_low_hp2_x2p = m_L_ap_low_hp2_x_267;
			t_sample L_ap_low_hp2_y1p = m_L_ap_low_hp2_y_266;
			t_sample L_ap_low_hp2_y2p = m_L_ap_low_hp2_y_265;
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_267 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_21 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_265 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_266 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = m_L_m1_x_35;
			t_sample L_m1_x2p = m_L_m1_x_288;
			t_sample L_m1_y1p = m_L_m1_y_287;
			t_sample L_m1_y2p = m_L_m1_y_286;
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_288 = L_m1_x1p;
			m_L_m1_x_35 = L_rest;
			m_L_m1_y_286 = L_m1_y1p;
			m_L_m1_y_287 = L_mid_s1;
			t_sample L_m2_x1p = m_L_m2_x_33;
			t_sample L_m2_x2p = m_L_m2_x_285;
			t_sample L_m2_y1p = m_L_m2_y_284;
			t_sample L_m2_y2p = m_L_m2_y_283;
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_285 = L_m2_x1p;
			m_L_m2_x_33 = L_mid_s1;
			m_L_m2_y_283 = L_m2_y1p;
			m_L_m2_y_284 = L_mid;
			t_sample L_u1_x1p = m_L_u1_x_31;
			t_sample L_u1_x2p = m_L_u1_x_282;
			t_sample L_u1_y1p = m_L_u1_y_281;
			t_sample L_u1_y2p = m_L_u1_y_280;
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_282 = L_u1_x1p;
			m_L_u1_x_31 = L_rest;
			m_L_u1_y_280 = L_u1_y1p;
			m_L_u1_y_281 = L_high_s1;
			t_sample L_u2_x1p = m_L_u2_x_29;
			t_sample L_u2_x2p = m_L_u2_x_279;
			t_sample L_u2_y1p = m_L_u2_y_278;
			t_sample L_u2_y2p = m_L_u2_y_277;
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_279 = L_u2_x1p;
			m_L_u2_x_29 = L_high_s1;
			m_L_u2_y_277 = L_u2_y1p;
			m_L_u2_y_278 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_328 = ((minb_327 < R_loF) ? minb_327 : R_loF);
			t_sample R_loF_8729 = ((((int)10) < maxb_328) ? maxb_328 : ((int)10));
			t_sample maxb_330 = ((minb_329 < R_hiF) ? minb_329 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_330) ? maxb_330 : ((int)10));
			t_sample maxb_331 = (R_loF_8729 + ((int)1));
			t_sample R_hiF_8730 = ((R_hiFr < maxb_331) ? maxb_331 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_8729), R_sr);
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
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_8730), R_sr);
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
			t_sample R_l1_x1p = m_R_l1_x_42;
			t_sample R_l1_x2p = m_R_l1_x_240;
			t_sample R_l1_y1p = m_R_l1_y_239;
			t_sample R_l1_y2p = m_R_l1_y_238;
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_240 = R_l1_x1p;
			m_R_l1_x_42 = R_x;
			m_R_l1_y_238 = R_l1_y1p;
			m_R_l1_y_239 = R_low_s1;
			t_sample R_l2_x1p = m_R_l2_x_40;
			t_sample R_l2_x2p = m_R_l2_x_237;
			t_sample R_l2_y1p = m_R_l2_y_236;
			t_sample R_l2_y2p = m_R_l2_y_235;
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_237 = R_l2_x1p;
			m_R_l2_x_40 = R_low_s1;
			m_R_l2_y_235 = R_l2_y1p;
			m_R_l2_y_236 = R_low_raw;
			t_sample R_h1_x1p = m_R_h1_x_38;
			t_sample R_h1_x2p = m_R_h1_x_234;
			t_sample R_h1_y1p = m_R_h1_y_233;
			t_sample R_h1_y2p = m_R_h1_y_232;
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_234 = R_h1_x1p;
			m_R_h1_x_38 = R_x;
			m_R_h1_y_232 = R_h1_y1p;
			m_R_h1_y_233 = R_rest_s1;
			t_sample R_h2_x1p = m_R_h2_x_36;
			t_sample R_h2_x2p = m_R_h2_x_231;
			t_sample R_h2_y1p = m_R_h2_y_230;
			t_sample R_h2_y2p = m_R_h2_y_229;
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_231 = R_h2_x1p;
			m_R_h2_x_36 = R_rest_s1;
			m_R_h2_y_229 = R_h2_y1p;
			m_R_h2_y_230 = R_rest;
			t_sample R_ap_low_lp1_x1p = m_R_ap_low_lp1_x_26;
			t_sample R_ap_low_lp1_x2p = m_R_ap_low_lp1_x_216;
			t_sample R_ap_low_lp1_y1p = m_R_ap_low_lp1_y_215;
			t_sample R_ap_low_lp1_y2p = m_R_ap_low_lp1_y_214;
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_216 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_26 = R_low_raw;
			m_R_ap_low_lp1_y_214 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_215 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = m_R_ap_low_lp2_x_24;
			t_sample R_ap_low_lp2_x2p = m_R_ap_low_lp2_x_213;
			t_sample R_ap_low_lp2_y1p = m_R_ap_low_lp2_y_212;
			t_sample R_ap_low_lp2_y2p = m_R_ap_low_lp2_y_211;
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_213 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_24 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_211 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_212 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = m_R_ap_low_hp1_x_22;
			t_sample R_ap_low_hp1_x2p = m_R_ap_low_hp1_x_210;
			t_sample R_ap_low_hp1_y1p = m_R_ap_low_hp1_y_209;
			t_sample R_ap_low_hp1_y2p = m_R_ap_low_hp1_y_208;
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_210 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_22 = R_low_raw;
			m_R_ap_low_hp1_y_208 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_209 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = m_R_ap_low_hp2_x_20;
			t_sample R_ap_low_hp2_x2p = m_R_ap_low_hp2_x_207;
			t_sample R_ap_low_hp2_y1p = m_R_ap_low_hp2_y_206;
			t_sample R_ap_low_hp2_y2p = m_R_ap_low_hp2_y_205;
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_207 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_20 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_205 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_206 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = m_R_m1_x_34;
			t_sample R_m1_x2p = m_R_m1_x_228;
			t_sample R_m1_y1p = m_R_m1_y_227;
			t_sample R_m1_y2p = m_R_m1_y_226;
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_228 = R_m1_x1p;
			m_R_m1_x_34 = R_rest;
			m_R_m1_y_226 = R_m1_y1p;
			m_R_m1_y_227 = R_mid_s1;
			t_sample R_m2_x1p = m_R_m2_x_32;
			t_sample R_m2_x2p = m_R_m2_x_225;
			t_sample R_m2_y1p = m_R_m2_y_224;
			t_sample R_m2_y2p = m_R_m2_y_223;
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_225 = R_m2_x1p;
			m_R_m2_x_32 = R_mid_s1;
			m_R_m2_y_223 = R_m2_y1p;
			m_R_m2_y_224 = R_mid;
			t_sample R_u1_x1p = m_R_u1_x_30;
			t_sample R_u1_x2p = m_R_u1_x_222;
			t_sample R_u1_y1p = m_R_u1_y_221;
			t_sample R_u1_y2p = m_R_u1_y_220;
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_222 = R_u1_x1p;
			m_R_u1_x_30 = R_rest;
			m_R_u1_y_220 = R_u1_y1p;
			m_R_u1_y_221 = R_high_s1;
			t_sample R_u2_x1p = m_R_u2_x_28;
			t_sample R_u2_x2p = m_R_u2_x_219;
			t_sample R_u2_y1p = m_R_u2_y_218;
			t_sample R_u2_y2p = m_R_u2_y_217;
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_219 = R_u2_x1p;
			m_R_u2_x_28 = R_high_s1;
			m_R_u2_y_217 = R_u2_y1p;
			m_R_u2_y_218 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_332 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_332) ? maxb_332 : ((int)0));
			t_sample maxb_333 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_333) ? maxb_333 : ((int)0));
			t_sample maxb_334 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_334) ? maxb_334 : ((int)0));
			t_sample maxb_335 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_335) ? maxb_335 : ((t_sample)1e-09));
			t_sample wLow_8732 = safediv(wLow, wSum);
			t_sample wMid_8733 = safediv(wMid, wSum);
			t_sample wHigh_8734 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_8732 * lowL) + (wMid_8733 * midL)) + (wHigh_8734 * highL));
			t_sample preBandR = (((wLow_8732 * lowR) + (wMid_8733 * midR)) + (wHigh_8734 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			int soloOn = ((wBandSolo > ((t_sample)0.5)) * (scSm > ((t_sample)0.5)));
			t_sample iffalse_336 = (sumBandsL - preBandL);
			t_sample bypassWhenActiveL = (soloOn ? ((int)0) : iffalse_336);
			t_sample iffalse_337 = (sumBandsR - preBandR);
			t_sample bypassWhenActiveR = (soloOn ? ((int)0) : iffalse_337);
			t_sample mix_8856 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_8856;
			t_sample mix_8857 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_8857;
			t_sample L_loF_8735 = smoothHpfFreq;
			t_sample L_hiF_8736 = smoothLpfFreq;
			t_sample L_x_8737 = lIn;
			t_sample maxb_339 = ((minb_338 < L_loF_8735) ? minb_338 : L_loF_8735);
			t_sample L_loF_8741 = ((((int)10) < maxb_339) ? maxb_339 : ((int)10));
			t_sample maxb_341 = ((minb_340 < L_hiF_8736) ? minb_340 : L_hiF_8736);
			t_sample L_hiFr_8742 = ((((int)10) < maxb_341) ? maxb_341 : ((int)10));
			t_sample maxb_342 = (L_loF_8741 + ((int)1));
			t_sample L_hiF_8743 = ((L_hiFr_8742 < maxb_342) ? maxb_342 : L_hiFr_8742);
			t_sample L_w0_lo_8744 = safediv((((t_sample)6.2831853071796) * L_loF_8741), L_sr_8740);
			t_sample L_cos_lo_8745 = cos(L_w0_lo_8744);
			t_sample L_sin_lo_8746 = sin(L_w0_lo_8744);
			t_sample L_alpha_lo_8747 = (L_sin_lo_8746 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_8748 = (((int)1) + L_alpha_lo_8747);
			t_sample L_a1_lo_8749 = (((int)-2) * L_cos_lo_8745);
			t_sample L_a2_lo_8750 = (((int)1) - L_alpha_lo_8747);
			t_sample L_lp_b0_l_8751 = safediv(((((int)1) - L_cos_lo_8745) * ((t_sample)0.5)), L_a0_lo_8748);
			t_sample L_lp_b1_l_8752 = safediv((((int)1) - L_cos_lo_8745), L_a0_lo_8748);
			t_sample L_lp_b2_l_8753 = L_lp_b0_l_8751;
			t_sample L_lp_a1_l_8754 = safediv(L_a1_lo_8749, L_a0_lo_8748);
			t_sample L_lp_a2_l_8755 = safediv(L_a2_lo_8750, L_a0_lo_8748);
			t_sample L_hp_b0_l_8756 = safediv(((((int)1) + L_cos_lo_8745) * ((t_sample)0.5)), L_a0_lo_8748);
			t_sample L_hp_b1_l_8757 = safediv((-(((int)1) + L_cos_lo_8745)), L_a0_lo_8748);
			t_sample L_hp_b2_l_8758 = L_hp_b0_l_8756;
			t_sample L_hp_a1_l_8759 = L_lp_a1_l_8754;
			t_sample L_hp_a2_l_8760 = L_lp_a2_l_8755;
			t_sample L_w0_hi_8761 = safediv((((t_sample)6.2831853071796) * L_hiF_8743), L_sr_8740);
			t_sample L_cos_hi_8762 = cos(L_w0_hi_8761);
			t_sample L_sin_hi_8763 = sin(L_w0_hi_8761);
			t_sample L_alpha_hi_8764 = (L_sin_hi_8763 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_8765 = (((int)1) + L_alpha_hi_8764);
			t_sample L_a1_hi_8766 = (((int)-2) * L_cos_hi_8762);
			t_sample L_a2_hi_8767 = (((int)1) - L_alpha_hi_8764);
			t_sample L_lp_b0_h_8768 = safediv(((((int)1) - L_cos_hi_8762) * ((t_sample)0.5)), L_a0_hi_8765);
			t_sample L_lp_b1_h_8769 = safediv((((int)1) - L_cos_hi_8762), L_a0_hi_8765);
			t_sample L_lp_b2_h_8770 = L_lp_b0_h_8768;
			t_sample L_lp_a1_h_8771 = safediv(L_a1_hi_8766, L_a0_hi_8765);
			t_sample L_lp_a2_h_8772 = safediv(L_a2_hi_8767, L_a0_hi_8765);
			t_sample L_hp_b0_h_8773 = safediv(((((int)1) + L_cos_hi_8762) * ((t_sample)0.5)), L_a0_hi_8765);
			t_sample L_hp_b1_h_8774 = safediv((-(((int)1) + L_cos_hi_8762)), L_a0_hi_8765);
			t_sample L_hp_b2_h_8775 = L_hp_b0_h_8773;
			t_sample L_hp_a1_h_8776 = L_lp_a1_h_8771;
			t_sample L_hp_a2_h_8777 = L_lp_a2_h_8772;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_19;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_264;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_263;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_262;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_8751 * L_x_8737) + (L_lp_b1_l_8752 * L_ap1_lp1_x1p)) + (L_lp_b2_l_8753 * L_ap1_lp1_x2p)) - (L_lp_a1_l_8754 * L_ap1_lp1_y1p)) - (L_lp_a2_l_8755 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_264 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_19 = L_x_8737;
			m_L_ap1_lp1_y_262 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_263 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_17;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_261;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_260;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_259;
			t_sample L_ap1_lp = (((((L_lp_b0_l_8751 * L_ap1_lp_s1) + (L_lp_b1_l_8752 * L_ap1_lp2_x1p)) + (L_lp_b2_l_8753 * L_ap1_lp2_x2p)) - (L_lp_a1_l_8754 * L_ap1_lp2_y1p)) - (L_lp_a2_l_8755 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_261 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_17 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_259 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_260 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_15;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_258;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_257;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_256;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_8756 * L_x_8737) + (L_hp_b1_l_8757 * L_ap1_hp1_x1p)) + (L_hp_b2_l_8758 * L_ap1_hp1_x2p)) - (L_hp_a1_l_8759 * L_ap1_hp1_y1p)) - (L_hp_a2_l_8760 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_258 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_15 = L_x_8737;
			m_L_ap1_hp1_y_256 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_257 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_13;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_255;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_254;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_253;
			t_sample L_ap1_hp = (((((L_hp_b0_l_8756 * L_ap1_hp_s1) + (L_hp_b1_l_8757 * L_ap1_hp2_x1p)) + (L_hp_b2_l_8758 * L_ap1_hp2_x2p)) - (L_hp_a1_l_8759 * L_ap1_hp2_y1p)) - (L_hp_a2_l_8760 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_255 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_13 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_253 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_254 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_11;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_252;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_251;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_250;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_8768 * L_stage1_out) + (L_lp_b1_h_8769 * L_ap2_lp1_x1p)) + (L_lp_b2_h_8770 * L_ap2_lp1_x2p)) - (L_lp_a1_h_8771 * L_ap2_lp1_y1p)) - (L_lp_a2_h_8772 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_252 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_11 = L_stage1_out;
			m_L_ap2_lp1_y_250 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_251 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_9;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_249;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_248;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_247;
			t_sample L_ap2_lp = (((((L_lp_b0_h_8768 * L_ap2_lp_s1) + (L_lp_b1_h_8769 * L_ap2_lp2_x1p)) + (L_lp_b2_h_8770 * L_ap2_lp2_x2p)) - (L_lp_a1_h_8771 * L_ap2_lp2_y1p)) - (L_lp_a2_h_8772 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_249 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_9 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_247 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_248 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_7;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_246;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_245;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_244;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_8773 * L_stage1_out) + (L_hp_b1_h_8774 * L_ap2_hp1_x1p)) + (L_hp_b2_h_8775 * L_ap2_hp1_x2p)) - (L_hp_a1_h_8776 * L_ap2_hp1_y1p)) - (L_hp_a2_h_8777 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_246 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_7 = L_stage1_out;
			m_L_ap2_hp1_y_244 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_245 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_5;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_243;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_242;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_241;
			t_sample L_ap2_hp = (((((L_hp_b0_h_8773 * L_ap2_hp_s1) + (L_hp_b1_h_8774 * L_ap2_hp2_x1p)) + (L_hp_b2_h_8775 * L_ap2_hp2_x2p)) - (L_hp_a1_h_8776 * L_ap2_hp2_y1p)) - (L_hp_a2_h_8777 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_243 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_5 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_241 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_242 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_8778 = smoothHpfFreq;
			t_sample R_hiF_8779 = smoothLpfFreq;
			t_sample R_x_8780 = rIn;
			t_sample maxb_344 = ((minb_343 < R_loF_8778) ? minb_343 : R_loF_8778);
			t_sample R_loF_8784 = ((((int)10) < maxb_344) ? maxb_344 : ((int)10));
			t_sample maxb_346 = ((minb_345 < R_hiF_8779) ? minb_345 : R_hiF_8779);
			t_sample R_hiFr_8785 = ((((int)10) < maxb_346) ? maxb_346 : ((int)10));
			t_sample maxb_347 = (R_loF_8784 + ((int)1));
			t_sample R_hiF_8786 = ((R_hiFr_8785 < maxb_347) ? maxb_347 : R_hiFr_8785);
			t_sample R_w0_lo_8787 = safediv((((t_sample)6.2831853071796) * R_loF_8784), R_sr_8783);
			t_sample R_cos_lo_8788 = cos(R_w0_lo_8787);
			t_sample R_sin_lo_8789 = sin(R_w0_lo_8787);
			t_sample R_alpha_lo_8790 = (R_sin_lo_8789 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_8791 = (((int)1) + R_alpha_lo_8790);
			t_sample R_a1_lo_8792 = (((int)-2) * R_cos_lo_8788);
			t_sample R_a2_lo_8793 = (((int)1) - R_alpha_lo_8790);
			t_sample R_lp_b0_l_8794 = safediv(((((int)1) - R_cos_lo_8788) * ((t_sample)0.5)), R_a0_lo_8791);
			t_sample R_lp_b1_l_8795 = safediv((((int)1) - R_cos_lo_8788), R_a0_lo_8791);
			t_sample R_lp_b2_l_8796 = R_lp_b0_l_8794;
			t_sample R_lp_a1_l_8797 = safediv(R_a1_lo_8792, R_a0_lo_8791);
			t_sample R_lp_a2_l_8798 = safediv(R_a2_lo_8793, R_a0_lo_8791);
			t_sample R_hp_b0_l_8799 = safediv(((((int)1) + R_cos_lo_8788) * ((t_sample)0.5)), R_a0_lo_8791);
			t_sample R_hp_b1_l_8800 = safediv((-(((int)1) + R_cos_lo_8788)), R_a0_lo_8791);
			t_sample R_hp_b2_l_8801 = R_hp_b0_l_8799;
			t_sample R_hp_a1_l_8802 = R_lp_a1_l_8797;
			t_sample R_hp_a2_l_8803 = R_lp_a2_l_8798;
			t_sample R_w0_hi_8804 = safediv((((t_sample)6.2831853071796) * R_hiF_8786), R_sr_8783);
			t_sample R_cos_hi_8805 = cos(R_w0_hi_8804);
			t_sample R_sin_hi_8806 = sin(R_w0_hi_8804);
			t_sample R_alpha_hi_8807 = (R_sin_hi_8806 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_8808 = (((int)1) + R_alpha_hi_8807);
			t_sample R_a1_hi_8809 = (((int)-2) * R_cos_hi_8805);
			t_sample R_a2_hi_8810 = (((int)1) - R_alpha_hi_8807);
			t_sample R_lp_b0_h_8811 = safediv(((((int)1) - R_cos_hi_8805) * ((t_sample)0.5)), R_a0_hi_8808);
			t_sample R_lp_b1_h_8812 = safediv((((int)1) - R_cos_hi_8805), R_a0_hi_8808);
			t_sample R_lp_b2_h_8813 = R_lp_b0_h_8811;
			t_sample R_lp_a1_h_8814 = safediv(R_a1_hi_8809, R_a0_hi_8808);
			t_sample R_lp_a2_h_8815 = safediv(R_a2_hi_8810, R_a0_hi_8808);
			t_sample R_hp_b0_h_8816 = safediv(((((int)1) + R_cos_hi_8805) * ((t_sample)0.5)), R_a0_hi_8808);
			t_sample R_hp_b1_h_8817 = safediv((-(((int)1) + R_cos_hi_8805)), R_a0_hi_8808);
			t_sample R_hp_b2_h_8818 = R_hp_b0_h_8816;
			t_sample R_hp_a1_h_8819 = R_lp_a1_h_8814;
			t_sample R_hp_a2_h_8820 = R_lp_a2_h_8815;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_18;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_204;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_203;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_202;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_8794 * R_x_8780) + (R_lp_b1_l_8795 * R_ap1_lp1_x1p)) + (R_lp_b2_l_8796 * R_ap1_lp1_x2p)) - (R_lp_a1_l_8797 * R_ap1_lp1_y1p)) - (R_lp_a2_l_8798 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_204 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_18 = R_x_8780;
			m_R_ap1_lp1_y_202 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_203 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_16;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_201;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_200;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_199;
			t_sample R_ap1_lp = (((((R_lp_b0_l_8794 * R_ap1_lp_s1) + (R_lp_b1_l_8795 * R_ap1_lp2_x1p)) + (R_lp_b2_l_8796 * R_ap1_lp2_x2p)) - (R_lp_a1_l_8797 * R_ap1_lp2_y1p)) - (R_lp_a2_l_8798 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_201 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_16 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_199 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_200 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_14;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_198;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_197;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_196;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_8799 * R_x_8780) + (R_hp_b1_l_8800 * R_ap1_hp1_x1p)) + (R_hp_b2_l_8801 * R_ap1_hp1_x2p)) - (R_hp_a1_l_8802 * R_ap1_hp1_y1p)) - (R_hp_a2_l_8803 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_198 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_14 = R_x_8780;
			m_R_ap1_hp1_y_196 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_197 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_12;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_195;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_194;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_193;
			t_sample R_ap1_hp = (((((R_hp_b0_l_8799 * R_ap1_hp_s1) + (R_hp_b1_l_8800 * R_ap1_hp2_x1p)) + (R_hp_b2_l_8801 * R_ap1_hp2_x2p)) - (R_hp_a1_l_8802 * R_ap1_hp2_y1p)) - (R_hp_a2_l_8803 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_195 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_12 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_193 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_194 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_10;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_192;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_191;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_190;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_8811 * R_stage1_out) + (R_lp_b1_h_8812 * R_ap2_lp1_x1p)) + (R_lp_b2_h_8813 * R_ap2_lp1_x2p)) - (R_lp_a1_h_8814 * R_ap2_lp1_y1p)) - (R_lp_a2_h_8815 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_192 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_10 = R_stage1_out;
			m_R_ap2_lp1_y_190 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_191 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_8;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_189;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_188;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_187;
			t_sample R_ap2_lp = (((((R_lp_b0_h_8811 * R_ap2_lp_s1) + (R_lp_b1_h_8812 * R_ap2_lp2_x1p)) + (R_lp_b2_h_8813 * R_ap2_lp2_x2p)) - (R_lp_a1_h_8814 * R_ap2_lp2_y1p)) - (R_lp_a2_h_8815 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_189 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_8 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_187 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_188 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_6;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_186;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_185;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_184;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_8816 * R_stage1_out) + (R_hp_b1_h_8817 * R_ap2_hp1_x1p)) + (R_hp_b2_h_8818 * R_ap2_hp1_x2p)) - (R_hp_a1_h_8819 * R_ap2_hp1_y1p)) - (R_hp_a2_h_8820 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_186 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_6 = R_stage1_out;
			m_R_ap2_hp1_y_184 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_185 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_4;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_183;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_182;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_181;
			t_sample R_ap2_hp = (((((R_hp_b0_h_8816 * R_ap2_hp_s1) + (R_hp_b1_h_8817 * R_ap2_hp2_x1p)) + (R_hp_b2_h_8818 * R_ap2_hp2_x2p)) - (R_hp_a1_h_8819 * R_ap2_hp2_y1p)) - (R_hp_a2_h_8820 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_183 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_4 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_181 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_182 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_8858 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample mix_8859 = (rIn + (scSm * (dryCompR - rIn)));
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
			t_sample lLs_8821 = (((((a0Ls * lFiltered) + (a1Ls * m_tiltLsL_75)) + (a2Ls * m_tiltLsL_76)) - (b1Ls * m_tiltLsL_73)) - (b2Ls * m_tiltLsL_74));
			m_tiltLsL_76 = m_tiltLsL_75;
			m_tiltLsL_75 = lFiltered;
			m_tiltLsL_74 = m_tiltLsL_73;
			m_tiltLsL_73 = lLs_8821;
			t_sample rLs_8822 = (((((a0Ls * rFiltered) + (a1Ls * m_tiltLsR_71)) + (a2Ls * m_tiltLsR_72)) - (b1Ls * m_tiltLsR_69)) - (b2Ls * m_tiltLsR_70));
			m_tiltLsR_72 = m_tiltLsR_71;
			m_tiltLsR_71 = rFiltered;
			m_tiltLsR_70 = m_tiltLsR_69;
			m_tiltLsR_69 = rLs_8822;
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
			t_sample lTiltRaw = (((((a0Hs * lLs_8821) + (a1Hs * m_tiltHsL_67)) + (a2Hs * m_tiltHsL_68)) - (b1Hs * m_tiltHsL_65)) - (b2Hs * m_tiltHsL_66));
			m_tiltHsL_68 = m_tiltHsL_67;
			m_tiltHsL_67 = lLs_8821;
			m_tiltHsL_66 = m_tiltHsL_65;
			m_tiltHsL_65 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_8822) + (a1Hs * m_tiltHsR_63)) + (a2Hs * m_tiltHsR_64)) - (b1Hs * m_tiltHsR_61)) - (b2Hs * m_tiltHsR_62));
			m_tiltHsR_64 = m_tiltHsR_63;
			m_tiltHsR_63 = rLs_8822;
			m_tiltHsR_62 = m_tiltHsR_61;
			m_tiltHsR_61 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cs)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sn) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cs)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sn) + (b2Ls * sin2)));
			t_sample maxb_348 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_348) ? maxb_348 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cs)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sn) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cs)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sn) + (b2Hs * sin2)));
			t_sample maxb_349 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_349) ? maxb_349 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_350 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_350) ? maxb_350 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample mode = smoothedMode;
			t_sample maxb_351 = (((int)1) - fabs((mode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_351) ? maxb_351 : ((int)0));
			t_sample maxb_352 = (((int)1) - fabs((mode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_352) ? maxb_352 : ((int)0));
			t_sample maxb_353 = (((int)1) - fabs((mode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_353) ? maxb_353 : ((int)0));
			t_sample maxb_354 = (((int)1) - fabs((mode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_354) ? maxb_354 : ((int)0));
			t_sample maxb_355 = (((int)1) - fabs((mode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_355) ? maxb_355 : ((int)0));
			t_sample maxb_356 = (((int)1) - fabs((mode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_356) ? maxb_356 : ((int)0));
			t_sample maxb_357 = (((int)1) - fabs((mode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_357) ? maxb_357 : ((int)0));
			t_sample maxb_358 = (((int)1) - fabs((mode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_358) ? maxb_358 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_8823 = safediv(w0, sumWeights);
			t_sample w_8824 = safediv(w1, sumWeights);
			t_sample w_8825 = safediv(w2, sumWeights);
			t_sample w_8826 = safediv(w3, sumWeights);
			t_sample w_8827 = safediv(w4, sumWeights);
			t_sample w_8828 = safediv(w5, sumWeights);
			t_sample w_8829 = safediv(w6, sumWeights);
			t_sample w_8830 = safediv(w7, sumWeights);
			t_sample return_361;
			t_sample return_362;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_361, return_362);
			t_sample softL_A = return_361;
			t_sample softR_A = return_362;
			t_sample return_367;
			t_sample return_368;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_367, return_368);
			t_sample sigmL_A = return_367;
			t_sample sigmR_A = return_368;
			t_sample return_371;
			t_sample return_372;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_371, return_372);
			t_sample rectL_A = return_371;
			t_sample rectR_A = return_372;
			t_sample return_375;
			t_sample return_376;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_375, return_376);
			t_sample fuzz1L_A = return_375;
			t_sample fuzz1R_A = return_376;
			t_sample return_381;
			t_sample return_382;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_381, return_382);
			t_sample tanhL_A = return_381;
			t_sample tanhR_A = return_382;
			t_sample return_387;
			t_sample return_388;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_387, return_388);
			t_sample recthL_A = return_387;
			t_sample recthR_A = return_388;
			t_sample return_389;
			t_sample return_390;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_389, return_390);
			t_sample atanL_A = return_389;
			t_sample atanR_A = return_390;
			t_sample return_399;
			t_sample return_400;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_399, return_400);
			t_sample hardL_A = return_399;
			t_sample hardR_A = return_400;
			t_sample distL_A = ((((((((softL_A * w_8823) + (sigmL_A * w_8824)) + (rectL_A * w_8825)) + (fuzz1L_A * w_8826)) + (tanhL_A * w_8827)) + (recthL_A * w_8828)) + (atanL_A * w_8829)) + (hardL_A * w_8830));
			t_sample distR_A = ((((((((softR_A * w_8823) + (sigmR_A * w_8824)) + (rectR_A * w_8825)) + (fuzz1R_A * w_8826)) + (tanhR_A * w_8827)) + (recthR_A * w_8828)) + (atanR_A * w_8829)) + (hardR_A * w_8830));
			t_sample preOutL = __m_dcblock_401(distL_A);
			t_sample preOutR = __m_dcblock_402(distR_A);
			t_sample return_403;
			t_sample return_404;
			softclip_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_403, return_404);
			t_sample softL_B = return_403;
			t_sample softR_B = return_404;
			t_sample return_405;
			t_sample return_406;
			sigmoid_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_405, return_406);
			t_sample sigmL_B = return_405;
			t_sample sigmR_B = return_406;
			t_sample return_407;
			t_sample return_408;
			rectF_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_407, return_408);
			t_sample rectL_B = return_407;
			t_sample rectR_B = return_408;
			t_sample return_409;
			t_sample return_410;
			fuzzExp1_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_409, return_410);
			t_sample fuzz1L_B = return_409;
			t_sample fuzz1R_B = return_410;
			t_sample return_411;
			t_sample return_412;
			tangenteHiperbolica_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_411, return_412);
			t_sample tanhL_B = return_411;
			t_sample tanhR_B = return_412;
			t_sample return_413;
			t_sample return_414;
			rectH_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_413, return_414);
			t_sample recthL_B = return_413;
			t_sample recthR_B = return_414;
			t_sample return_415;
			t_sample return_416;
			arctangent_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_415, return_416);
			t_sample atanL_B = return_415;
			t_sample atanR_B = return_416;
			t_sample return_417;
			t_sample return_418;
			hardClip_d_d_d_d_d(preDistInL, preDistInR, drive, dc, ceiling, return_417, return_418);
			t_sample hardL_B = return_417;
			t_sample hardR_B = return_418;
			t_sample distL_B = ((((((((softL_B * w_8823) + (sigmL_B * w_8824)) + (rectL_B * w_8825)) + (fuzz1L_B * w_8826)) + (tanhL_B * w_8827)) + (recthL_B * w_8828)) + (atanL_B * w_8829)) + (hardL_B * w_8830));
			t_sample distR_B = ((((((((softR_B * w_8823) + (sigmR_B * w_8824)) + (rectR_B * w_8825)) + (fuzz1R_B * w_8826)) + (tanhR_B * w_8827)) + (recthR_B * w_8828)) + (atanR_B * w_8829)) + (hardR_B * w_8830));
			t_sample postInL = __m_dcblock_419(distL_B);
			t_sample postInR = __m_dcblock_420(distR_B);
			t_sample postLsL = (((((a0Ls * postInL) + (a1Ls * m_postTiltLsL_58)) + (a2Ls * m_postTiltLsL_59)) - (b1Ls * m_postTiltLsL_56)) - (b2Ls * m_postTiltLsL_57));
			m_postTiltLsL_59 = m_postTiltLsL_58;
			m_postTiltLsL_58 = postInL;
			m_postTiltLsL_57 = m_postTiltLsL_56;
			m_postTiltLsL_56 = postLsL;
			t_sample postLsR = (((((a0Ls * postInR) + (a1Ls * m_postTiltLsR_54)) + (a2Ls * m_postTiltLsR_55)) - (b1Ls * m_postTiltLsR_52)) - (b2Ls * m_postTiltLsR_53));
			m_postTiltLsR_55 = m_postTiltLsR_54;
			m_postTiltLsR_54 = postInR;
			m_postTiltLsR_53 = m_postTiltLsR_52;
			m_postTiltLsR_52 = postLsR;
			t_sample postTiltRawL = (((((a0Hs * postLsL) + (a1Hs * m_postTiltHsL_50)) + (a2Hs * m_postTiltHsL_51)) - (b1Hs * m_postTiltHsL_48)) - (b2Hs * m_postTiltHsL_49));
			m_postTiltHsL_51 = m_postTiltHsL_50;
			m_postTiltHsL_50 = postLsL;
			m_postTiltHsL_49 = m_postTiltHsL_48;
			m_postTiltHsL_48 = postTiltRawL;
			t_sample postTiltRawR = (((((a0Hs * postLsR) + (a1Hs * m_postTiltHsR_46)) + (a2Hs * m_postTiltHsR_47)) - (b1Hs * m_postTiltHsR_44)) - (b2Hs * m_postTiltHsR_45));
			m_postTiltHsR_47 = m_postTiltHsR_46;
			m_postTiltHsR_46 = postLsR;
			m_postTiltHsR_45 = m_postTiltHsR_44;
			m_postTiltHsR_44 = postTiltRawR;
			t_sample postTiltL = (postTiltRawL * gPivot);
			t_sample postTiltR = (postTiltRawR * gPivot);
			t_sample mix_8860 = (preOutL + (wPost * (postTiltL - preOutL)));
			t_sample mix_8861 = (preOutR + (wPost * (postTiltR - preOutR)));
			t_sample mix_8862 = (lTilt + (wDist * (mix_8860 - lTilt)));
			t_sample mix_8863 = (rTilt + (wDist * (mix_8861 - rTilt)));
			t_sample return_421;
			t_sample return_422;
			bitCrusher_d_d_d(mix_8862, mix_8863, bits, return_421, return_422);
			t_sample bitL = return_421;
			t_sample bitR = return_422;
			t_sample bcL = __m_dcblock_423(bitL);
			t_sample bcR = __m_dcblock_424(bitR);
			t_sample mix_8864 = (mix_8862 + (bitson * (bcL - mix_8862)));
			t_sample mix_8865 = (mix_8863 + (bitson * (bcR - mix_8863)));
			t_sample maxb_425 = floor((m_hDownsample_90 + ((int)1)));
			t_sample deciFactor = ((((int)1) < maxb_425) ? maxb_425 : ((int)1));
			int enableNow = (downsampleOn > ((t_sample)0.5));
			int enableEdge = (enableNow > m_dsEnablePrev_77);
			m_dsEnablePrev_77 = enableNow;
			t_sample inc = safediv(((int)1), deciFactor);
			t_sample iffalse_426 = (m_dsPhase_79 + inc);
			m_dsPhase_79 = (enableEdge ? ((int)0) : iffalse_426);
			m_dsPhase_79 = (m_dsPhase_79 - floor(m_dsPhase_79));
			int dsEdgeWrap = (m_dsPhase_79 < m_dsTrigPrev_78);
			int dsEdge = (((enableEdge + dsEdgeWrap) + (deciFactor == ((int)1))) > ((t_sample)0.5));
			m_dsTrigPrev_78 = m_dsPhase_79;
			__m_latch_427 = ((dsEdge != 0) ? mix_8864 : __m_latch_427);
			t_sample dsHeldL = __m_latch_427;
			__m_latch_428 = ((dsEdge != 0) ? mix_8865 : __m_latch_428);
			t_sample dsHeldR = __m_latch_428;
			t_sample mix_8866 = (mix_8864 + (downsampleOn * (dsHeldL - mix_8864)));
			t_sample mix_8867 = (mix_8865 + (downsampleOn * (dsHeldR - mix_8865)));
			t_sample wetWithMakeupL = ((mix_8866 * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((mix_8867 * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample mix_8868 = (mix_8858 + (drywet * (wetWithMakeupL - mix_8858)));
			t_sample mix_8869 = (mix_8859 + (drywet * (wetWithMakeupR - mix_8859)));
			t_sample clamp_8871 = ((mix_8868 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_8868 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_8868));
			t_sample mix_8870 = (mix_8868 + (safeOn * (clamp_8871 - mix_8868)));
			t_sample clamp_8873 = ((mix_8869 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_8869 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_8869));
			t_sample mix_8872 = (mix_8869 + (safeOn * (clamp_8873 - mix_8869)));
			t_sample mix_8874 = (lIn + (bypass * (mix_8870 - lIn)));
			t_sample mix_8875 = (rIn + (bypass * (mix_8872 - rIn)));
			t_sample out1 = mix_8874;
			t_sample out5 = rTrimmed;
			t_sample out4 = lTrimmed;
			t_sample out2 = mix_8875;
			t_sample out3 = ((int)0);
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_p_SAFELIMITON(t_param _value) {
		m_p_SAFELIMITON_301 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_BANDSOLO(t_param _value) {
		m_p_BANDSOLO_302 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_DISTON(t_param _value) {
		m_p_DISTON_303 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_TILTPOS(t_param _value) {
		m_p_TILTPOS_304 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_305 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_306 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_307 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_308 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_309 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_310 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_311 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_312 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_313 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_314 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_315 = (_value < 2 ? 2 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_316 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_317 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_318 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_319 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_320 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_321 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void softclip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lNorm = safediv((lWithDC * dr), cell);
		t_sample rNorm = safediv((rWithDC * dr), cell);
		t_sample lCubic = (lNorm - (((lNorm * lNorm) * lNorm) * ((t_sample)0.33333333333333)));
		t_sample rCubic = (rNorm - (((rNorm * rNorm) * rNorm) * ((t_sample)0.33333333333333)));
		t_sample lLimited = (((lNorm > 0) ? 1 : ((lNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		t_sample rLimited = (((rNorm > 0) ? 1 : ((rNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		int cond_359 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_359 ? lCubic : lLimited);
		int cond_360 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_360 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample factor = ((-((int)1)) * dr);
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lWithDC))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rWithDC))))) - ((int)1));
		t_sample v_363 = (l * cell);
		t_sample min_364 = (-cell);
		t_sample lOut = ((v_363 <= min_364) ? min_364 : ((v_363 >= cell) ? cell : v_363));
		t_sample v_365 = (r * cell);
		t_sample min_366 = (-cell);
		t_sample rOut = ((v_365 <= min_366) ? min_366 : ((v_365 >= cell) ? cell : v_365));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample l = ((((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0)) * fabs((lWithDC * dr))) * ((t_sample)0.707));
		t_sample r = ((((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0)) * fabs((rWithDC * dr))) * ((t_sample)0.707));
		t_sample min_369 = (-cell);
		t_sample lOut = ((l <= min_369) ? min_369 : ((l >= cell) ? cell : l));
		t_sample min_370 = (-cell);
		t_sample rOut = ((r <= min_370) ? min_370 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		int signl = ((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0));
		int signr = ((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0));
		t_sample lScaled = fabs((lWithDC * dr));
		t_sample rScaled = fabs((rWithDC * dr));
		t_sample l = (signl * (((int)1) - exp((-lScaled))));
		t_sample r = (signr * (((int)1) - exp((-rScaled))));
		t_sample min_373 = (-cell);
		t_sample lOut = ((l <= min_373) ? min_373 : ((l >= cell) ? cell : l));
		t_sample min_374 = (-cell);
		t_sample rOut = ((r <= min_374) ? min_374 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample v_377 = (lWithDC * dr);
		t_sample min_378 = (-cell);
		t_sample l = ((v_377 <= min_378) ? min_378 : ((v_377 >= cell) ? cell : v_377));
		t_sample v_379 = (rWithDC * dr);
		t_sample min_380 = (-cell);
		t_sample r = ((v_379 <= min_380) ? min_380 : ((v_379 >= cell) ? cell : v_379));
		t_sample lOut = safediv(tanh(l), tanh(dr));
		t_sample rOut = safediv(tanh(r), tanh(dr));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectH_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lPositive = ((lWithDC < ((int)0)) ? ((int)0) : lWithDC);
		t_sample rPositive = ((rWithDC < ((int)0)) ? ((int)0) : rWithDC);
		t_sample v_383 = ((lPositive * dr) * ((t_sample)0.5));
		t_sample min_384 = (-cell);
		t_sample l = ((v_383 <= min_384) ? min_384 : ((v_383 >= cell) ? cell : v_383));
		t_sample v_385 = ((rPositive * dr) * ((t_sample)0.5));
		t_sample min_386 = (-cell);
		t_sample r = ((v_385 <= min_386) ? min_386 : ((v_385 >= cell) ? cell : v_385));
		out1 = l;
		out2 = r;
		
	};
	inline void arctangent_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lScaled = ((lWithDC * dr) * ((int)2));
		t_sample rScaled = ((rWithDC * dr) * ((int)2));
		t_sample l = ((((int)2) * ((t_sample)0.31830988618379)) * atan(lScaled));
		t_sample r = ((((int)2) * ((t_sample)0.31830988618379)) * atan(rScaled));
		t_sample lOut = (l * cell);
		t_sample rOut = (r * cell);
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void hardClip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lDriven = (lWithDC * dr);
		t_sample rDriven = (rWithDC * dr);
		int cond_391 = (lDriven > cell);
		int cond_392 = (lDriven < (-cell));
		t_sample iftrue_393 = (-cell);
		t_sample iffalse_394 = (cond_392 ? iftrue_393 : lDriven);
		t_sample l = (cond_391 ? cell : iffalse_394);
		int cond_395 = (rDriven > cell);
		int cond_396 = (rDriven < (-cell));
		t_sample iftrue_397 = (-cell);
		t_sample iffalse_398 = (cond_396 ? iftrue_397 : rDriven);
		t_sample r = (cond_395 ? cell : iffalse_398);
		out1 = l;
		out2 = r;
		
	};
	inline void bitCrusher_d_d_d(t_sample inl, t_sample inr, t_sample bits, t_sample& out1, t_sample& out2) {
		t_sample steps = (safepow(((int)2), bits) - ((int)1));
		t_sample invSteps = safediv(((int)1), steps);
		t_sample l = (ceil((inl * steps)) * invSteps);
		t_sample r = (ceil((inr * steps)) * invSteps);
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
int num_params() { return 21; }

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
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_321; break;
		case 1: *value = self->m_b_DRIVE_320; break;
		case 2: *value = self->m_c_DC_319; break;
		case 3: *value = self->m_d_MODE_318; break;
		case 4: *value = self->m_e_CEILING_317; break;
		case 5: *value = self->m_f_BYPASS_316; break;
		case 6: *value = self->m_g_BITS_315; break;
		case 7: *value = self->m_h_BITSON_314; break;
		case 8: *value = self->m_i_TILT_313; break;
		case 9: *value = self->m_j_HPF_312; break;
		case 10: *value = self->m_k_INPUT_309; break;
		case 11: *value = self->m_k_LPF_311; break;
		case 12: *value = self->m_l_OUTPUT_308; break;
		case 13: *value = self->m_l_SC_310; break;
		case 14: *value = self->m_m_DOWNSAMPLE_307; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_306; break;
		case 16: *value = self->m_o_BAND_305; break;
		case 17: *value = self->m_p_BANDSOLO_302; break;
		case 18: *value = self->m_p_DISTON_303; break;
		case 19: *value = self->m_p_SAFELIMITON_301; break;
		case 20: *value = self->m_p_TILTPOS_304; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(21 * sizeof(ParamInfo));
	self->__commonstate.numparams = 21;
	// initialize parameter 0 ("m_a_DRYWET_321")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_321;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_320")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_320;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_319")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_319;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_318")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_318;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_317")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_317;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_316")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_316;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_315")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_315;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 2;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_314")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_314;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_313")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_313;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_312")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_312;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_309")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_309;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_311")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_311;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_308")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_308;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_310")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_310;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_307")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_307;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_306")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_306;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_305")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_305;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_p_BANDSOLO_302")
	pi = self->__commonstate.params + 17;
	pi->name = "p_BANDSOLO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_BANDSOLO_302;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_p_DISTON_303")
	pi = self->__commonstate.params + 18;
	pi->name = "p_DISTON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_DISTON_303;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_p_SAFELIMITON_301")
	pi = self->__commonstate.params + 19;
	pi->name = "p_SAFELIMITON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_SAFELIMITON_301;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_p_TILTPOS_304")
	pi = self->__commonstate.params + 20;
	pi->name = "p_TILTPOS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_TILTPOS_304;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
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
