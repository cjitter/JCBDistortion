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
	DCBlock __m_dcblock_487;
	DCBlock __m_dcblock_491;
	DCBlock __m_dcblock_488;
	DCBlock __m_dcblock_492;
	DCBlock __m_dcblock_469;
	DCBlock __m_dcblock_470;
	int __exception;
	int vectorsize;
	t_sample m_R_ap_low_lp2_x_231;
	t_sample m_R_ap_low_lp2_y_230;
	t_sample m_R_ap_low_lp2_y_229;
	t_sample m_R_ap_low_lp1_y_232;
	t_sample m_R_u2_y_235;
	t_sample m_R_ap_low_lp1_x_234;
	t_sample m_R_ap_low_lp1_y_233;
	t_sample m_R_ap_low_hp1_x_228;
	t_sample m_R_ap_low_hp1_y_227;
	t_sample m_R_ap_low_hp2_y_223;
	t_sample m_R_ap_low_hp2_x_225;
	t_sample m_R_ap1_lp1_y_220;
	t_sample m_R_ap1_lp2_x_219;
	t_sample m_R_ap1_lp2_y_218;
	t_sample m_R_ap_low_hp1_y_226;
	t_sample m_R_ap1_lp1_y_221;
	t_sample m_R_u2_y_236;
	t_sample m_R_ap1_lp1_x_222;
	t_sample m_R_ap_low_hp2_y_224;
	t_sample m_R_u2_x_237;
	t_sample m_R_u1_x_240;
	t_sample m_R_u1_y_239;
	t_sample m_R_h1_x_252;
	t_sample m_R_h1_y_251;
	t_sample m_R_h1_y_250;
	t_sample m_R_h2_x_249;
	t_sample m_R_l2_y_253;
	t_sample m_R_l2_x_255;
	t_sample m_R_l2_y_254;
	t_sample m_R_l1_y_256;
	t_sample m_R_u1_y_238;
	t_sample m_R_h2_y_248;
	t_sample m_R_m1_x_246;
	t_sample m_R_m2_y_241;
	t_sample m_R_ap1_lp2_y_217;
	t_sample m_R_h2_y_247;
	t_sample m_R_m2_y_242;
	t_sample m_R_m1_y_244;
	t_sample m_R_m2_x_243;
	t_sample m_R_m1_y_245;
	t_sample m_R_ap1_hp1_x_216;
	t_sample m_R_ap1_hp2_x_213;
	t_sample m_R_ap1_hp1_y_214;
	t_sample m_h1_y_188;
	t_sample m_h1_y_187;
	t_sample m_h2_x_186;
	t_sample m_h2_x_185;
	t_sample m_h1_x_189;
	t_sample m_l2_y_191;
	t_sample m_h1_x_190;
	t_sample m_l2_y_192;
	t_sample m_l2_x_193;
	t_sample m_h2_y_184;
	t_sample m_m1_x_182;
	t_sample m_m2_x_177;
	t_sample m_m2_y_176;
	t_sample m_h2_y_183;
	t_sample m_m2_x_178;
	t_sample m_m1_y_180;
	t_sample m_m1_y_179;
	t_sample m_m1_x_181;
	t_sample m_R_ap1_hp1_y_215;
	t_sample m_l2_x_194;
	t_sample m_l1_y_196;
	t_sample m_R_ap2_lp1_y_209;
	t_sample m_R_ap2_lp1_y_208;
	t_sample m_R_ap2_lp2_x_207;
	t_sample m_R_ap2_lp2_y_206;
	t_sample m_R_ap2_lp1_x_210;
	t_sample m_R_ap1_hp2_y_212;
	t_sample m_R_ap1_hp2_y_211;
	t_sample m_R_l1_y_257;
	t_sample m_l1_y_195;
	t_sample m_R_ap2_lp2_y_205;
	t_sample m_R_ap2_hp1_y_203;
	t_sample m_l1_x_198;
	t_sample m_l1_x_197;
	t_sample m_R_ap2_hp1_x_204;
	t_sample m_R_ap2_hp2_y_199;
	t_sample m_R_ap2_hp2_x_201;
	t_sample m_R_ap2_hp2_y_200;
	t_sample m_R_ap2_hp1_y_202;
	t_sample m_R_l1_x_258;
	t_sample m_L_ap2_hp1_y_262;
	t_sample m_L_ap2_hp2_y_260;
	t_sample m_L_l1_y_316;
	t_sample m_L_l2_x_315;
	t_sample m_L_l2_y_314;
	t_sample m_L_l2_y_313;
	t_sample m_L_l1_y_317;
	t_sample m_r_TONEFREQ_319;
	t_sample m_L_l1_x_318;
	t_sample m_q_TONEON_320;
	t_sample m_p_SAFELIMITON_321;
	t_sample m_L_h1_x_312;
	t_sample m_L_h1_y_310;
	t_sample m_L_m1_y_305;
	t_sample m_L_m1_y_304;
	t_sample m_L_m2_x_303;
	t_sample m_L_h1_y_311;
	t_sample m_L_m1_x_306;
	t_sample m_L_h2_y_308;
	t_sample m_L_h2_y_307;
	t_sample m_L_h2_x_309;
	t_sample m_L_m2_y_302;
	t_sample m_p_BANDSOLO_322;
	t_sample m_p_TILTPOS_324;
	t_sample m_e_CEILING_337;
	t_sample m_f_BYPASS_336;
	t_sample m_g_BITS_335;
	t_sample m_h_BITSON_334;
	t_sample m_d_MODE_338;
	t_sample m_b_DRIVE_340;
	t_sample m_c_DC_339;
	t_sample m_a_DRYWET_341;
	t_sample m_p_DISTON_323;
	t_sample m_i_TILT_333;
	t_sample m_k_LPF_331;
	t_sample m_n_DOWNSAMPLEON_326;
	t_sample m_o_BAND_325;
	t_sample m_j_HPF_332;
	t_sample m_m_DOWNSAMPLE_327;
	t_sample m_k_INPUT_329;
	t_sample m_l_OUTPUT_328;
	t_sample m_l_SC_330;
	t_sample m_L_ap2_hp2_y_259;
	t_sample m_L_m2_y_301;
	t_sample m_L_u1_y_299;
	t_sample m_L_ap1_hp2_x_273;
	t_sample m_L_ap1_hp2_y_272;
	t_sample m_L_ap1_hp2_y_271;
	t_sample m_L_ap2_lp1_x_270;
	t_sample m_L_ap1_hp1_y_274;
	t_sample m_L_ap1_hp1_x_276;
	t_sample m_L_ap1_hp1_y_275;
	t_sample m_L_ap1_lp2_y_277;
	t_sample m_L_ap1_lp2_y_278;
	t_sample m_L_ap2_lp1_y_269;
	t_sample m_L_ap2_lp2_x_267;
	t_sample m_m2_y_175;
	t_sample m_L_ap2_hp2_x_261;
	t_sample m_L_ap2_lp1_y_268;
	t_sample m_L_ap2_hp1_y_263;
	t_sample m_L_ap2_lp2_y_265;
	t_sample m_L_ap2_hp1_x_264;
	t_sample m_L_ap2_lp2_y_266;
	t_sample m_L_u1_x_300;
	t_sample m_L_ap1_lp2_x_279;
	t_sample m_L_ap1_lp1_y_281;
	t_sample m_L_ap_low_lp1_x_294;
	t_sample m_L_ap_low_lp1_y_293;
	t_sample m_L_ap_low_lp1_y_292;
	t_sample m_L_ap_low_lp2_x_291;
	t_sample m_L_u2_y_295;
	t_sample m_L_u2_x_297;
	t_sample m_L_u2_y_296;
	t_sample m_L_u1_y_298;
	t_sample m_L_ap1_lp1_y_280;
	t_sample m_L_ap_low_lp2_y_290;
	t_sample m_L_ap_low_hp1_x_288;
	t_sample m_L_ap_low_hp2_y_283;
	t_sample m_L_ap1_lp1_x_282;
	t_sample m_L_ap_low_lp2_y_289;
	t_sample m_L_ap_low_hp2_y_284;
	t_sample m_L_ap_low_hp1_y_286;
	t_sample m_L_ap_low_hp2_x_285;
	t_sample m_L_ap_low_hp1_y_287;
	t_sample m_u1_x_174;
	t_sample m_u1_x_173;
	t_sample m_u1_y_172;
	t_sample m_L_h1_x_57;
	t_sample m_R_h1_x_56;
	t_sample m_L_h2_x_55;
	t_sample m_R_h2_x_54;
	t_sample m_R_l2_x_58;
	t_sample m_R_l1_x_60;
	t_sample m_L_l2_x_59;
	t_sample m_L_l1_x_61;
	t_sample m_postTiltHsR_62;
	t_sample m_L_m1_x_53;
	t_sample m_L_m2_x_51;
	t_sample m_R_u2_x_46;
	t_sample m_L_ap_low_lp1_x_45;
	t_sample m_R_ap_low_lp1_x_44;
	t_sample m_R_m1_x_52;
	t_sample m_L_u2_x_47;
	t_sample m_L_u1_x_49;
	t_sample m_R_u1_x_48;
	t_sample m_R_m2_x_50;
	t_sample m_L_ap_low_lp2_x_43;
	t_sample m_postTiltHsR_63;
	t_sample m_postTiltHsR_65;
	t_sample m_tiltHsR_79;
	t_sample m_hTiltPos_78;
	t_sample m_postTiltLsL_77;
	t_sample m_postTiltLsL_76;
	t_sample m_tiltHsR_80;
	t_sample m_tiltHsR_82;
	t_sample m_tiltHsR_81;
	t_sample m_tiltHsL_83;
	t_sample m_postTiltHsR_64;
	t_sample m_postTiltLsL_75;
	t_sample m_postTiltLsR_73;
	t_sample m_postTiltHsL_68;
	t_sample m_postTiltHsL_67;
	t_sample m_postTiltHsL_66;
	t_sample m_postTiltLsL_74;
	t_sample m_postTiltHsL_69;
	t_sample m_postTiltLsR_71;
	t_sample m_postTiltLsR_70;
	t_sample m_postTiltLsR_72;
	t_sample m_tiltHsL_84;
	t_sample m_R_ap_low_lp2_x_42;
	t_sample m_R_ap_low_hp1_x_40;
	t_sample m_toneL_y_13;
	t_sample m_toneR_x_12;
	t_sample m_toneR_x_11;
	t_sample m_toneR_y_10;
	t_sample m_toneL_y_14;
	t_sample m_toneL_x_16;
	t_sample m_toneL_x_15;
	t_sample m_hToneFreq_17;
	t_sample m_hToneOn_18;
	t_sample m_toneR_y_9;
	t_sample m_toneApL_x_7;
	t_sample m_toneApR_y_2;
	t_sample m_toneApR_y_1;
	t_sample samplerate;
	t_sample m_toneApL_x_8;
	t_sample m_toneApR_x_3;
	t_sample m_toneApL_y_5;
	t_sample m_toneApR_x_4;
	t_sample m_toneApL_y_6;
	t_sample m_L_ap_low_hp1_x_41;
	t_sample m_hSafeLimitOn_19;
	t_sample m_hDistOn_21;
	t_sample m_L_ap1_lp2_x_35;
	t_sample m_R_ap1_lp2_x_34;
	t_sample m_L_ap1_hp1_x_33;
	t_sample m_R_ap1_hp1_x_32;
	t_sample m_R_ap1_lp1_x_36;
	t_sample m_R_ap_low_hp2_x_38;
	t_sample m_L_ap1_lp1_x_37;
	t_sample m_L_ap_low_hp2_x_39;
	t_sample m_hBandSolo_20;
	t_sample m_L_ap1_hp2_x_31;
	t_sample m_L_ap2_lp1_x_29;
	t_sample m_R_ap2_hp1_x_24;
	t_sample m_L_ap2_hp2_x_23;
	t_sample m_R_ap2_hp2_x_22;
	t_sample m_R_ap1_hp2_x_30;
	t_sample m_L_ap2_hp1_x_25;
	t_sample m_L_ap2_lp2_x_27;
	t_sample m_R_ap2_lp2_x_26;
	t_sample m_R_ap2_lp1_x_28;
	t_sample __m_latch_495;
	t_sample m_tiltHsL_85;
	t_sample m_tiltLsR_87;
	t_sample m_ap1_lp2_x_145;
	t_sample m_ap1_lp2_y_144;
	t_sample m_ap1_lp2_y_143;
	t_sample m_ap1_hp1_x_142;
	t_sample m_ap1_lp2_x_146;
	t_sample m_ap1_lp1_y_148;
	t_sample m_ap1_lp1_y_147;
	t_sample m_ap1_lp1_x_149;
	t_sample m_ap1_lp1_x_150;
	t_sample m_ap1_hp1_x_141;
	t_sample m_ap1_hp1_y_139;
	t_sample m_ap2_lp1_x_134;
	t_sample m_ap2_lp1_x_133;
	t_sample m_ap2_lp1_y_132;
	t_sample m_ap1_hp1_y_140;
	t_sample m_ap1_hp2_y_135;
	t_sample m_ap1_hp2_x_137;
	t_sample m_ap1_hp2_y_136;
	t_sample m_ap1_hp2_x_138;
	t_sample m_ap2_lp1_y_131;
	t_sample m_ap_low_hp2_y_151;
	t_sample m_ap_low_hp2_x_153;
	t_sample m_u2_y_167;
	t_sample m_ap_low_lp1_x_166;
	t_sample m_ap_low_lp1_x_165;
	t_sample m_ap_low_lp1_y_164;
	t_sample m_u2_y_168;
	t_sample m_u2_x_170;
	t_sample m_u2_x_169;
	t_sample m_u1_y_171;
	t_sample m_ap_low_hp2_y_152;
	t_sample m_ap_low_lp1_y_163;
	t_sample m_ap_low_lp2_x_161;
	t_sample m_ap_low_hp1_y_156;
	t_sample m_ap_low_hp1_y_155;
	t_sample m_ap_low_hp2_x_154;
	t_sample m_ap_low_lp2_x_162;
	t_sample m_ap_low_hp1_x_157;
	t_sample m_ap_low_lp2_y_159;
	t_sample m_ap_low_hp1_x_158;
	t_sample m_ap_low_lp2_y_160;
	t_sample m_tiltHsL_86;
	t_sample m_ap2_lp2_x_130;
	t_sample m_ap2_lp2_y_128;
	t_sample m_hpfFreqHistory_101;
	t_sample m_lpfFreqHistory_100;
	t_sample m_scEnableHistory_99;
	t_sample m_dsPhasor_98;
	t_sample m_lpfR_z_102;
	t_sample m_hpfR_z_104;
	t_sample m_lpfL_z_103;
	t_sample m_hpfL_z_105;
	t_sample m_hBypass_106;
	t_sample m_dsPhase_97;
	t_sample m_dsEnablePrev_95;
	t_sample m_tiltLsR_90;
	t_sample m_tiltLsR_89;
	t_sample m_tiltLsR_88;
	t_sample m_dsTrigPrev_96;
	t_sample m_tiltLsL_91;
	t_sample m_tiltLsL_93;
	t_sample m_tiltLsL_92;
	t_sample m_tiltLsL_94;
	t_sample m_ap2_lp2_x_129;
	t_sample m_hDownsampleOn_107;
	t_sample m_hMode_109;
	t_sample m_ap2_hp1_y_123;
	t_sample m_ap2_hp2_x_122;
	t_sample m_ap2_hp2_x_121;
	t_sample m_ap2_hp2_y_120;
	t_sample m_ap2_hp1_y_124;
	t_sample m_ap2_hp1_x_126;
	t_sample m_ap2_hp1_x_125;
	t_sample m_ap2_lp2_y_127;
	t_sample m_hDownsample_108;
	t_sample m_ap2_hp2_y_119;
	t_sample m_hDrive_117;
	t_sample m_hTilt_112;
	t_sample m_hInput_111;
	t_sample m_hOutput_110;
	t_sample m_hBand_118;
	t_sample m_hBitson_113;
	t_sample m_hDrywet_115;
	t_sample m_hBits_114;
	t_sample m_hDc_116;
	t_sample __m_latch_496;
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
		m_toneR_y_9 = ((int)0);
		m_toneR_y_10 = ((int)0);
		m_toneR_x_11 = ((int)0);
		m_toneR_x_12 = ((int)0);
		m_toneL_y_13 = ((int)0);
		m_toneL_y_14 = ((int)0);
		m_toneL_x_15 = ((int)0);
		m_toneL_x_16 = ((int)0);
		m_hToneFreq_17 = ((int)12000);
		m_hToneOn_18 = ((int)0);
		m_hSafeLimitOn_19 = ((int)0);
		m_hBandSolo_20 = ((int)0);
		m_hDistOn_21 = ((int)1);
		m_R_ap2_hp2_x_22 = ((int)0);
		m_L_ap2_hp2_x_23 = ((int)0);
		m_R_ap2_hp1_x_24 = ((int)0);
		m_L_ap2_hp1_x_25 = ((int)0);
		m_R_ap2_lp2_x_26 = ((int)0);
		m_L_ap2_lp2_x_27 = ((int)0);
		m_R_ap2_lp1_x_28 = ((int)0);
		m_L_ap2_lp1_x_29 = ((int)0);
		m_R_ap1_hp2_x_30 = ((int)0);
		m_L_ap1_hp2_x_31 = ((int)0);
		m_R_ap1_hp1_x_32 = ((int)0);
		m_L_ap1_hp1_x_33 = ((int)0);
		m_R_ap1_lp2_x_34 = ((int)0);
		m_L_ap1_lp2_x_35 = ((int)0);
		m_R_ap1_lp1_x_36 = ((int)0);
		m_L_ap1_lp1_x_37 = ((int)0);
		m_R_ap_low_hp2_x_38 = ((int)0);
		m_L_ap_low_hp2_x_39 = ((int)0);
		m_R_ap_low_hp1_x_40 = ((int)0);
		m_L_ap_low_hp1_x_41 = ((int)0);
		m_R_ap_low_lp2_x_42 = ((int)0);
		m_L_ap_low_lp2_x_43 = ((int)0);
		m_R_ap_low_lp1_x_44 = ((int)0);
		m_L_ap_low_lp1_x_45 = ((int)0);
		m_R_u2_x_46 = ((int)0);
		m_L_u2_x_47 = ((int)0);
		m_R_u1_x_48 = ((int)0);
		m_L_u1_x_49 = ((int)0);
		m_R_m2_x_50 = ((int)0);
		m_L_m2_x_51 = ((int)0);
		m_R_m1_x_52 = ((int)0);
		m_L_m1_x_53 = ((int)0);
		m_R_h2_x_54 = ((int)0);
		m_L_h2_x_55 = ((int)0);
		m_R_h1_x_56 = ((int)0);
		m_L_h1_x_57 = ((int)0);
		m_R_l2_x_58 = ((int)0);
		m_L_l2_x_59 = ((int)0);
		m_R_l1_x_60 = ((int)0);
		m_L_l1_x_61 = ((int)0);
		m_postTiltHsR_62 = ((int)0);
		m_postTiltHsR_63 = ((int)0);
		m_postTiltHsR_64 = ((int)0);
		m_postTiltHsR_65 = ((int)0);
		m_postTiltHsL_66 = ((int)0);
		m_postTiltHsL_67 = ((int)0);
		m_postTiltHsL_68 = ((int)0);
		m_postTiltHsL_69 = ((int)0);
		m_postTiltLsR_70 = ((int)0);
		m_postTiltLsR_71 = ((int)0);
		m_postTiltLsR_72 = ((int)0);
		m_postTiltLsR_73 = ((int)0);
		m_postTiltLsL_74 = ((int)0);
		m_postTiltLsL_75 = ((int)0);
		m_postTiltLsL_76 = ((int)0);
		m_postTiltLsL_77 = ((int)0);
		m_hTiltPos_78 = ((int)0);
		m_tiltHsR_79 = ((int)0);
		m_tiltHsR_80 = ((int)0);
		m_tiltHsR_81 = ((int)0);
		m_tiltHsR_82 = ((int)0);
		m_tiltHsL_83 = ((int)0);
		m_tiltHsL_84 = ((int)0);
		m_tiltHsL_85 = ((int)0);
		m_tiltHsL_86 = ((int)0);
		m_tiltLsR_87 = ((int)0);
		m_tiltLsR_88 = ((int)0);
		m_tiltLsR_89 = ((int)0);
		m_tiltLsR_90 = ((int)0);
		m_tiltLsL_91 = ((int)0);
		m_tiltLsL_92 = ((int)0);
		m_tiltLsL_93 = ((int)0);
		m_tiltLsL_94 = ((int)0);
		m_dsEnablePrev_95 = ((int)0);
		m_dsTrigPrev_96 = ((int)0);
		m_dsPhase_97 = ((int)0);
		m_dsPhasor_98 = ((int)0);
		m_scEnableHistory_99 = ((int)0);
		m_lpfFreqHistory_100 = ((int)0);
		m_hpfFreqHistory_101 = ((int)0);
		m_lpfR_z_102 = ((int)0);
		m_lpfL_z_103 = ((int)0);
		m_hpfR_z_104 = ((int)0);
		m_hpfL_z_105 = ((int)0);
		m_hBypass_106 = ((int)0);
		m_hDownsampleOn_107 = ((int)0);
		m_hDownsample_108 = ((int)0);
		m_hMode_109 = ((int)0);
		m_hOutput_110 = ((int)0);
		m_hInput_111 = ((int)0);
		m_hTilt_112 = ((int)0);
		m_hBitson_113 = ((int)0);
		m_hBits_114 = ((int)0);
		m_hDrywet_115 = ((int)0);
		m_hDc_116 = ((int)0);
		m_hDrive_117 = ((int)0);
		m_hBand_118 = ((int)1);
		m_ap2_hp2_y_119 = ((int)0);
		m_ap2_hp2_y_120 = ((int)0);
		m_ap2_hp2_x_121 = ((int)0);
		m_ap2_hp2_x_122 = ((int)0);
		m_ap2_hp1_y_123 = ((int)0);
		m_ap2_hp1_y_124 = ((int)0);
		m_ap2_hp1_x_125 = ((int)0);
		m_ap2_hp1_x_126 = ((int)0);
		m_ap2_lp2_y_127 = ((int)0);
		m_ap2_lp2_y_128 = ((int)0);
		m_ap2_lp2_x_129 = ((int)0);
		m_ap2_lp2_x_130 = ((int)0);
		m_ap2_lp1_y_131 = ((int)0);
		m_ap2_lp1_y_132 = ((int)0);
		m_ap2_lp1_x_133 = ((int)0);
		m_ap2_lp1_x_134 = ((int)0);
		m_ap1_hp2_y_135 = ((int)0);
		m_ap1_hp2_y_136 = ((int)0);
		m_ap1_hp2_x_137 = ((int)0);
		m_ap1_hp2_x_138 = ((int)0);
		m_ap1_hp1_y_139 = ((int)0);
		m_ap1_hp1_y_140 = ((int)0);
		m_ap1_hp1_x_141 = ((int)0);
		m_ap1_hp1_x_142 = ((int)0);
		m_ap1_lp2_y_143 = ((int)0);
		m_ap1_lp2_y_144 = ((int)0);
		m_ap1_lp2_x_145 = ((int)0);
		m_ap1_lp2_x_146 = ((int)0);
		m_ap1_lp1_y_147 = ((int)0);
		m_ap1_lp1_y_148 = ((int)0);
		m_ap1_lp1_x_149 = ((int)0);
		m_ap1_lp1_x_150 = ((int)0);
		m_ap_low_hp2_y_151 = ((int)0);
		m_ap_low_hp2_y_152 = ((int)0);
		m_ap_low_hp2_x_153 = ((int)0);
		m_ap_low_hp2_x_154 = ((int)0);
		m_ap_low_hp1_y_155 = ((int)0);
		m_ap_low_hp1_y_156 = ((int)0);
		m_ap_low_hp1_x_157 = ((int)0);
		m_ap_low_hp1_x_158 = ((int)0);
		m_ap_low_lp2_y_159 = ((int)0);
		m_ap_low_lp2_y_160 = ((int)0);
		m_ap_low_lp2_x_161 = ((int)0);
		m_ap_low_lp2_x_162 = ((int)0);
		m_ap_low_lp1_y_163 = ((int)0);
		m_ap_low_lp1_y_164 = ((int)0);
		m_ap_low_lp1_x_165 = ((int)0);
		m_ap_low_lp1_x_166 = ((int)0);
		m_u2_y_167 = ((int)0);
		m_u2_y_168 = ((int)0);
		m_u2_x_169 = ((int)0);
		m_u2_x_170 = ((int)0);
		m_u1_y_171 = ((int)0);
		m_u1_y_172 = ((int)0);
		m_u1_x_173 = ((int)0);
		m_u1_x_174 = ((int)0);
		m_m2_y_175 = ((int)0);
		m_m2_y_176 = ((int)0);
		m_m2_x_177 = ((int)0);
		m_m2_x_178 = ((int)0);
		m_m1_y_179 = ((int)0);
		m_m1_y_180 = ((int)0);
		m_m1_x_181 = ((int)0);
		m_m1_x_182 = ((int)0);
		m_h2_y_183 = ((int)0);
		m_h2_y_184 = ((int)0);
		m_h2_x_185 = ((int)0);
		m_h2_x_186 = ((int)0);
		m_h1_y_187 = ((int)0);
		m_h1_y_188 = ((int)0);
		m_h1_x_189 = ((int)0);
		m_h1_x_190 = ((int)0);
		m_l2_y_191 = ((int)0);
		m_l2_y_192 = ((int)0);
		m_l2_x_193 = ((int)0);
		m_l2_x_194 = ((int)0);
		m_l1_y_195 = ((int)0);
		m_l1_y_196 = ((int)0);
		m_l1_x_197 = ((int)0);
		m_l1_x_198 = ((int)0);
		m_R_ap2_hp2_y_199 = ((int)0);
		m_R_ap2_hp2_y_200 = ((int)0);
		m_R_ap2_hp2_x_201 = ((int)0);
		m_R_ap2_hp1_y_202 = ((int)0);
		m_R_ap2_hp1_y_203 = ((int)0);
		m_R_ap2_hp1_x_204 = ((int)0);
		m_R_ap2_lp2_y_205 = ((int)0);
		m_R_ap2_lp2_y_206 = ((int)0);
		m_R_ap2_lp2_x_207 = ((int)0);
		m_R_ap2_lp1_y_208 = ((int)0);
		m_R_ap2_lp1_y_209 = ((int)0);
		m_R_ap2_lp1_x_210 = ((int)0);
		m_R_ap1_hp2_y_211 = ((int)0);
		m_R_ap1_hp2_y_212 = ((int)0);
		m_R_ap1_hp2_x_213 = ((int)0);
		m_R_ap1_hp1_y_214 = ((int)0);
		m_R_ap1_hp1_y_215 = ((int)0);
		m_R_ap1_hp1_x_216 = ((int)0);
		m_R_ap1_lp2_y_217 = ((int)0);
		m_R_ap1_lp2_y_218 = ((int)0);
		m_R_ap1_lp2_x_219 = ((int)0);
		m_R_ap1_lp1_y_220 = ((int)0);
		m_R_ap1_lp1_y_221 = ((int)0);
		m_R_ap1_lp1_x_222 = ((int)0);
		m_R_ap_low_hp2_y_223 = ((int)0);
		m_R_ap_low_hp2_y_224 = ((int)0);
		m_R_ap_low_hp2_x_225 = ((int)0);
		m_R_ap_low_hp1_y_226 = ((int)0);
		m_R_ap_low_hp1_y_227 = ((int)0);
		m_R_ap_low_hp1_x_228 = ((int)0);
		m_R_ap_low_lp2_y_229 = ((int)0);
		m_R_ap_low_lp2_y_230 = ((int)0);
		m_R_ap_low_lp2_x_231 = ((int)0);
		m_R_ap_low_lp1_y_232 = ((int)0);
		m_R_ap_low_lp1_y_233 = ((int)0);
		m_R_ap_low_lp1_x_234 = ((int)0);
		m_R_u2_y_235 = ((int)0);
		m_R_u2_y_236 = ((int)0);
		m_R_u2_x_237 = ((int)0);
		m_R_u1_y_238 = ((int)0);
		m_R_u1_y_239 = ((int)0);
		m_R_u1_x_240 = ((int)0);
		m_R_m2_y_241 = ((int)0);
		m_R_m2_y_242 = ((int)0);
		m_R_m2_x_243 = ((int)0);
		m_R_m1_y_244 = ((int)0);
		m_R_m1_y_245 = ((int)0);
		m_R_m1_x_246 = ((int)0);
		m_R_h2_y_247 = ((int)0);
		m_R_h2_y_248 = ((int)0);
		m_R_h2_x_249 = ((int)0);
		m_R_h1_y_250 = ((int)0);
		m_R_h1_y_251 = ((int)0);
		m_R_h1_x_252 = ((int)0);
		m_R_l2_y_253 = ((int)0);
		m_R_l2_y_254 = ((int)0);
		m_R_l2_x_255 = ((int)0);
		m_R_l1_y_256 = ((int)0);
		m_R_l1_y_257 = ((int)0);
		m_R_l1_x_258 = ((int)0);
		m_L_ap2_hp2_y_259 = ((int)0);
		m_L_ap2_hp2_y_260 = ((int)0);
		m_L_ap2_hp2_x_261 = ((int)0);
		m_L_ap2_hp1_y_262 = ((int)0);
		m_L_ap2_hp1_y_263 = ((int)0);
		m_L_ap2_hp1_x_264 = ((int)0);
		m_L_ap2_lp2_y_265 = ((int)0);
		m_L_ap2_lp2_y_266 = ((int)0);
		m_L_ap2_lp2_x_267 = ((int)0);
		m_L_ap2_lp1_y_268 = ((int)0);
		m_L_ap2_lp1_y_269 = ((int)0);
		m_L_ap2_lp1_x_270 = ((int)0);
		m_L_ap1_hp2_y_271 = ((int)0);
		m_L_ap1_hp2_y_272 = ((int)0);
		m_L_ap1_hp2_x_273 = ((int)0);
		m_L_ap1_hp1_y_274 = ((int)0);
		m_L_ap1_hp1_y_275 = ((int)0);
		m_L_ap1_hp1_x_276 = ((int)0);
		m_L_ap1_lp2_y_277 = ((int)0);
		m_L_ap1_lp2_y_278 = ((int)0);
		m_L_ap1_lp2_x_279 = ((int)0);
		m_L_ap1_lp1_y_280 = ((int)0);
		m_L_ap1_lp1_y_281 = ((int)0);
		m_L_ap1_lp1_x_282 = ((int)0);
		m_L_ap_low_hp2_y_283 = ((int)0);
		m_L_ap_low_hp2_y_284 = ((int)0);
		m_L_ap_low_hp2_x_285 = ((int)0);
		m_L_ap_low_hp1_y_286 = ((int)0);
		m_L_ap_low_hp1_y_287 = ((int)0);
		m_L_ap_low_hp1_x_288 = ((int)0);
		m_L_ap_low_lp2_y_289 = ((int)0);
		m_L_ap_low_lp2_y_290 = ((int)0);
		m_L_ap_low_lp2_x_291 = ((int)0);
		m_L_ap_low_lp1_y_292 = ((int)0);
		m_L_ap_low_lp1_y_293 = ((int)0);
		m_L_ap_low_lp1_x_294 = ((int)0);
		m_L_u2_y_295 = ((int)0);
		m_L_u2_y_296 = ((int)0);
		m_L_u2_x_297 = ((int)0);
		m_L_u1_y_298 = ((int)0);
		m_L_u1_y_299 = ((int)0);
		m_L_u1_x_300 = ((int)0);
		m_L_m2_y_301 = ((int)0);
		m_L_m2_y_302 = ((int)0);
		m_L_m2_x_303 = ((int)0);
		m_L_m1_y_304 = ((int)0);
		m_L_m1_y_305 = ((int)0);
		m_L_m1_x_306 = ((int)0);
		m_L_h2_y_307 = ((int)0);
		m_L_h2_y_308 = ((int)0);
		m_L_h2_x_309 = ((int)0);
		m_L_h1_y_310 = ((int)0);
		m_L_h1_y_311 = ((int)0);
		m_L_h1_x_312 = ((int)0);
		m_L_l2_y_313 = ((int)0);
		m_L_l2_y_314 = ((int)0);
		m_L_l2_x_315 = ((int)0);
		m_L_l1_y_316 = ((int)0);
		m_L_l1_y_317 = ((int)0);
		m_L_l1_x_318 = ((int)0);
		m_r_TONEFREQ_319 = 12000;
		m_q_TONEON_320 = 0;
		m_p_SAFELIMITON_321 = 0;
		m_p_BANDSOLO_322 = 0;
		m_p_DISTON_323 = 1;
		m_p_TILTPOS_324 = 0;
		m_o_BAND_325 = 1;
		m_n_DOWNSAMPLEON_326 = 0;
		m_m_DOWNSAMPLE_327 = 0;
		m_l_OUTPUT_328 = 0;
		m_k_INPUT_329 = 0;
		m_l_SC_330 = 0;
		m_k_LPF_331 = 5000;
		m_j_HPF_332 = 250;
		m_i_TILT_333 = 0;
		m_h_BITSON_334 = 0;
		m_g_BITS_335 = 16;
		m_f_BYPASS_336 = 0;
		m_e_CEILING_337 = 0;
		m_d_MODE_338 = 0;
		m_c_DC_339 = 0;
		m_b_DRIVE_340 = 1;
		m_a_DRYWET_341 = 1;
		__m_dcblock_469.reset();
		__m_dcblock_470.reset();
		__m_dcblock_487.reset();
		__m_dcblock_488.reset();
		__m_dcblock_491.reset();
		__m_dcblock_492.reset();
		__m_latch_495 = 0;
		__m_latch_496 = 0;
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
		t_sample ceiling = dbtoa(m_e_CEILING_337);
		int L_sr = samplerate;
		t_sample minb_342 = (((t_sample)0.45) * L_sr);
		t_sample minb_344 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_347 = (((t_sample)0.45) * R_sr);
		t_sample minb_349 = (((t_sample)0.45) * R_sr);
		int L_sr_660 = samplerate;
		t_sample minb_358 = (((t_sample)0.45) * L_sr_660);
		t_sample minb_360 = (((t_sample)0.45) * L_sr_660);
		int R_sr_702 = samplerate;
		t_sample minb_363 = (((t_sample)0.45) * R_sr_702);
		t_sample minb_365 = (((t_sample)0.45) * R_sr_702);
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
			m_hDrive_117 = ((m_hDrive_117 * ((t_sample)0.999)) + (m_b_DRIVE_340 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_117;
			m_hDc_116 = ((m_hDc_116 * ((t_sample)0.999)) + (m_c_DC_339 * ((t_sample)0.001)));
			t_sample dc = m_hDc_116;
			m_hDrywet_115 = ((m_hDrywet_115 * ((t_sample)0.999)) + (m_a_DRYWET_341 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_115;
			m_hBits_114 = ((m_hBits_114 * ((t_sample)0.999)) + (m_g_BITS_335 * ((t_sample)0.001)));
			t_sample bits = m_hBits_114;
			m_hBitson_113 = ((m_hBitson_113 * ((t_sample)0.999)) + (m_h_BITSON_334 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_113;
			m_hTilt_112 = ((m_hTilt_112 * ((t_sample)0.999)) + (m_i_TILT_333 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_112;
			m_hInput_111 = ((m_hInput_111 * ((t_sample)0.999)) + (m_k_INPUT_329 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_111;
			m_hOutput_110 = ((m_hOutput_110 * ((t_sample)0.999)) + (m_l_OUTPUT_328 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_110;
			m_hBand_118 = ((m_hBand_118 * ((t_sample)0.999)) + (m_o_BAND_325 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_118;
			m_hMode_109 = ((m_hMode_109 * ((t_sample)0.99)) + (m_d_MODE_338 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_109;
			m_hDownsample_108 = ((m_hDownsample_108 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_327 * ((t_sample)0.001)));
			m_hDownsampleOn_107 = ((m_hDownsampleOn_107 * ((t_sample)0.9)) + (m_n_DOWNSAMPLEON_326 * ((t_sample)0.1)));
			t_sample downsampleOn = m_hDownsampleOn_107;
			m_hBypass_106 = ((m_hBypass_106 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_336) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_106;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_101 * ((t_sample)0.999)) + (m_j_HPF_332 * ((t_sample)0.001)));
			m_hpfFreqHistory_101 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_100 * ((t_sample)0.999)) + (m_k_LPF_331 * ((t_sample)0.001)));
			m_lpfFreqHistory_100 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_99 * ((t_sample)0.999)) + (m_l_SC_330 * ((t_sample)0.001)));
			m_scEnableHistory_99 = fixdenorm(smoothScEnable);
			m_hTiltPos_78 = ((m_hTiltPos_78 * ((t_sample)0.999)) + (m_p_TILTPOS_324 * ((t_sample)0.001)));
			t_sample wPost = ((m_hTiltPos_78 <= ((int)0)) ? ((int)0) : ((m_hTiltPos_78 >= ((int)1)) ? ((int)1) : m_hTiltPos_78));
			m_hDistOn_21 = ((m_hDistOn_21 * ((t_sample)0.999)) + (m_p_DISTON_323 * ((t_sample)0.001)));
			t_sample wDist = ((m_hDistOn_21 <= ((int)0)) ? ((int)0) : ((m_hDistOn_21 >= ((int)1)) ? ((int)1) : m_hDistOn_21));
			m_hBandSolo_20 = ((m_hBandSolo_20 * ((t_sample)0.999)) + (m_p_BANDSOLO_322 * ((t_sample)0.001)));
			t_sample wBandSolo = ((m_hBandSolo_20 <= ((int)0)) ? ((int)0) : ((m_hBandSolo_20 >= ((int)1)) ? ((int)1) : m_hBandSolo_20));
			m_hSafeLimitOn_19 = ((m_hSafeLimitOn_19 * ((t_sample)0.999)) + (m_p_SAFELIMITON_321 * ((t_sample)0.001)));
			t_sample safeOn = ((m_hSafeLimitOn_19 <= ((int)0)) ? ((int)0) : ((m_hSafeLimitOn_19 >= ((int)1)) ? ((int)1) : m_hSafeLimitOn_19));
			m_hToneOn_18 = ((m_hToneOn_18 * ((t_sample)0.9)) + (m_q_TONEON_320 * ((t_sample)0.1)));
			t_sample toneOn = ((m_hToneOn_18 <= ((int)0)) ? ((int)0) : ((m_hToneOn_18 >= ((int)1)) ? ((int)1) : m_hToneOn_18));
			m_hToneFreq_17 = ((m_hToneFreq_17 * ((t_sample)0.999)) + (m_r_TONEFREQ_319 * ((t_sample)0.001)));
			t_sample toneFreq = m_hToneFreq_17;
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_343 = ((minb_342 < L_loF) ? minb_342 : L_loF);
			t_sample L_loF_649 = ((((int)10) < maxb_343) ? maxb_343 : ((int)10));
			t_sample maxb_345 = ((minb_344 < L_hiF) ? minb_344 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_345) ? maxb_345 : ((int)10));
			t_sample maxb_346 = (L_loF_649 + ((int)1));
			t_sample L_hiF_650 = ((L_hiFr < maxb_346) ? maxb_346 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_649), L_sr);
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
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_650), L_sr);
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
			t_sample L_l1_x1p = fixdenorm(m_L_l1_x_61);
			t_sample L_l1_x2p = fixdenorm(m_L_l1_x_318);
			t_sample L_l1_y1p = fixdenorm(m_L_l1_y_317);
			t_sample L_l1_y2p = fixdenorm(m_L_l1_y_316);
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_318 = L_l1_x1p;
			m_L_l1_x_61 = L_x;
			m_L_l1_y_316 = L_l1_y1p;
			m_L_l1_y_317 = L_low_s1;
			t_sample L_l2_x1p = fixdenorm(m_L_l2_x_59);
			t_sample L_l2_x2p = fixdenorm(m_L_l2_x_315);
			t_sample L_l2_y1p = fixdenorm(m_L_l2_y_314);
			t_sample L_l2_y2p = fixdenorm(m_L_l2_y_313);
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_315 = L_l2_x1p;
			m_L_l2_x_59 = L_low_s1;
			m_L_l2_y_313 = L_l2_y1p;
			m_L_l2_y_314 = L_low_raw;
			t_sample L_h1_x1p = fixdenorm(m_L_h1_x_57);
			t_sample L_h1_x2p = fixdenorm(m_L_h1_x_312);
			t_sample L_h1_y1p = fixdenorm(m_L_h1_y_311);
			t_sample L_h1_y2p = fixdenorm(m_L_h1_y_310);
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_312 = L_h1_x1p;
			m_L_h1_x_57 = L_x;
			m_L_h1_y_310 = L_h1_y1p;
			m_L_h1_y_311 = L_rest_s1;
			t_sample L_h2_x1p = fixdenorm(m_L_h2_x_55);
			t_sample L_h2_x2p = fixdenorm(m_L_h2_x_309);
			t_sample L_h2_y1p = fixdenorm(m_L_h2_y_308);
			t_sample L_h2_y2p = fixdenorm(m_L_h2_y_307);
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_309 = L_h2_x1p;
			m_L_h2_x_55 = L_rest_s1;
			m_L_h2_y_307 = L_h2_y1p;
			m_L_h2_y_308 = L_rest;
			t_sample L_ap_low_lp1_x1p = fixdenorm(m_L_ap_low_lp1_x_45);
			t_sample L_ap_low_lp1_x2p = fixdenorm(m_L_ap_low_lp1_x_294);
			t_sample L_ap_low_lp1_y1p = fixdenorm(m_L_ap_low_lp1_y_293);
			t_sample L_ap_low_lp1_y2p = fixdenorm(m_L_ap_low_lp1_y_292);
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_294 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_45 = L_low_raw;
			m_L_ap_low_lp1_y_292 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_293 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = fixdenorm(m_L_ap_low_lp2_x_43);
			t_sample L_ap_low_lp2_x2p = fixdenorm(m_L_ap_low_lp2_x_291);
			t_sample L_ap_low_lp2_y1p = fixdenorm(m_L_ap_low_lp2_y_290);
			t_sample L_ap_low_lp2_y2p = fixdenorm(m_L_ap_low_lp2_y_289);
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_291 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_43 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_289 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_290 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = fixdenorm(m_L_ap_low_hp1_x_41);
			t_sample L_ap_low_hp1_x2p = fixdenorm(m_L_ap_low_hp1_x_288);
			t_sample L_ap_low_hp1_y1p = fixdenorm(m_L_ap_low_hp1_y_287);
			t_sample L_ap_low_hp1_y2p = fixdenorm(m_L_ap_low_hp1_y_286);
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_288 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_41 = L_low_raw;
			m_L_ap_low_hp1_y_286 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_287 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = fixdenorm(m_L_ap_low_hp2_x_39);
			t_sample L_ap_low_hp2_x2p = fixdenorm(m_L_ap_low_hp2_x_285);
			t_sample L_ap_low_hp2_y1p = fixdenorm(m_L_ap_low_hp2_y_284);
			t_sample L_ap_low_hp2_y2p = fixdenorm(m_L_ap_low_hp2_y_283);
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_285 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_39 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_283 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_284 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = fixdenorm(m_L_m1_x_53);
			t_sample L_m1_x2p = fixdenorm(m_L_m1_x_306);
			t_sample L_m1_y1p = fixdenorm(m_L_m1_y_305);
			t_sample L_m1_y2p = fixdenorm(m_L_m1_y_304);
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_306 = L_m1_x1p;
			m_L_m1_x_53 = L_rest;
			m_L_m1_y_304 = L_m1_y1p;
			m_L_m1_y_305 = L_mid_s1;
			t_sample L_m2_x1p = fixdenorm(m_L_m2_x_51);
			t_sample L_m2_x2p = fixdenorm(m_L_m2_x_303);
			t_sample L_m2_y1p = fixdenorm(m_L_m2_y_302);
			t_sample L_m2_y2p = fixdenorm(m_L_m2_y_301);
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_303 = L_m2_x1p;
			m_L_m2_x_51 = L_mid_s1;
			m_L_m2_y_301 = L_m2_y1p;
			m_L_m2_y_302 = L_mid;
			t_sample L_u1_x1p = fixdenorm(m_L_u1_x_49);
			t_sample L_u1_x2p = fixdenorm(m_L_u1_x_300);
			t_sample L_u1_y1p = fixdenorm(m_L_u1_y_299);
			t_sample L_u1_y2p = fixdenorm(m_L_u1_y_298);
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_300 = L_u1_x1p;
			m_L_u1_x_49 = L_rest;
			m_L_u1_y_298 = L_u1_y1p;
			m_L_u1_y_299 = L_high_s1;
			t_sample L_u2_x1p = fixdenorm(m_L_u2_x_47);
			t_sample L_u2_x2p = fixdenorm(m_L_u2_x_297);
			t_sample L_u2_y1p = fixdenorm(m_L_u2_y_296);
			t_sample L_u2_y2p = fixdenorm(m_L_u2_y_295);
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_297 = L_u2_x1p;
			m_L_u2_x_47 = L_high_s1;
			m_L_u2_y_295 = L_u2_y1p;
			m_L_u2_y_296 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_348 = ((minb_347 < R_loF) ? minb_347 : R_loF);
			t_sample R_loF_651 = ((((int)10) < maxb_348) ? maxb_348 : ((int)10));
			t_sample maxb_350 = ((minb_349 < R_hiF) ? minb_349 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_350) ? maxb_350 : ((int)10));
			t_sample maxb_351 = (R_loF_651 + ((int)1));
			t_sample R_hiF_652 = ((R_hiFr < maxb_351) ? maxb_351 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_651), R_sr);
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
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_652), R_sr);
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
			t_sample R_l1_x1p = fixdenorm(m_R_l1_x_60);
			t_sample R_l1_x2p = fixdenorm(m_R_l1_x_258);
			t_sample R_l1_y1p = fixdenorm(m_R_l1_y_257);
			t_sample R_l1_y2p = fixdenorm(m_R_l1_y_256);
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_258 = R_l1_x1p;
			m_R_l1_x_60 = R_x;
			m_R_l1_y_256 = R_l1_y1p;
			m_R_l1_y_257 = R_low_s1;
			t_sample R_l2_x1p = fixdenorm(m_R_l2_x_58);
			t_sample R_l2_x2p = fixdenorm(m_R_l2_x_255);
			t_sample R_l2_y1p = fixdenorm(m_R_l2_y_254);
			t_sample R_l2_y2p = fixdenorm(m_R_l2_y_253);
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_255 = R_l2_x1p;
			m_R_l2_x_58 = R_low_s1;
			m_R_l2_y_253 = R_l2_y1p;
			m_R_l2_y_254 = R_low_raw;
			t_sample R_h1_x1p = fixdenorm(m_R_h1_x_56);
			t_sample R_h1_x2p = fixdenorm(m_R_h1_x_252);
			t_sample R_h1_y1p = fixdenorm(m_R_h1_y_251);
			t_sample R_h1_y2p = fixdenorm(m_R_h1_y_250);
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_252 = R_h1_x1p;
			m_R_h1_x_56 = R_x;
			m_R_h1_y_250 = R_h1_y1p;
			m_R_h1_y_251 = R_rest_s1;
			t_sample R_h2_x1p = fixdenorm(m_R_h2_x_54);
			t_sample R_h2_x2p = fixdenorm(m_R_h2_x_249);
			t_sample R_h2_y1p = fixdenorm(m_R_h2_y_248);
			t_sample R_h2_y2p = fixdenorm(m_R_h2_y_247);
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_249 = R_h2_x1p;
			m_R_h2_x_54 = R_rest_s1;
			m_R_h2_y_247 = R_h2_y1p;
			m_R_h2_y_248 = R_rest;
			t_sample R_ap_low_lp1_x1p = fixdenorm(m_R_ap_low_lp1_x_44);
			t_sample R_ap_low_lp1_x2p = fixdenorm(m_R_ap_low_lp1_x_234);
			t_sample R_ap_low_lp1_y1p = fixdenorm(m_R_ap_low_lp1_y_233);
			t_sample R_ap_low_lp1_y2p = fixdenorm(m_R_ap_low_lp1_y_232);
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_234 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_44 = R_low_raw;
			m_R_ap_low_lp1_y_232 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_233 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = fixdenorm(m_R_ap_low_lp2_x_42);
			t_sample R_ap_low_lp2_x2p = fixdenorm(m_R_ap_low_lp2_x_231);
			t_sample R_ap_low_lp2_y1p = fixdenorm(m_R_ap_low_lp2_y_230);
			t_sample R_ap_low_lp2_y2p = fixdenorm(m_R_ap_low_lp2_y_229);
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_231 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_42 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_229 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_230 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = fixdenorm(m_R_ap_low_hp1_x_40);
			t_sample R_ap_low_hp1_x2p = fixdenorm(m_R_ap_low_hp1_x_228);
			t_sample R_ap_low_hp1_y1p = fixdenorm(m_R_ap_low_hp1_y_227);
			t_sample R_ap_low_hp1_y2p = fixdenorm(m_R_ap_low_hp1_y_226);
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_228 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_40 = R_low_raw;
			m_R_ap_low_hp1_y_226 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_227 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = fixdenorm(m_R_ap_low_hp2_x_38);
			t_sample R_ap_low_hp2_x2p = fixdenorm(m_R_ap_low_hp2_x_225);
			t_sample R_ap_low_hp2_y1p = fixdenorm(m_R_ap_low_hp2_y_224);
			t_sample R_ap_low_hp2_y2p = fixdenorm(m_R_ap_low_hp2_y_223);
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_225 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_38 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_223 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_224 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = fixdenorm(m_R_m1_x_52);
			t_sample R_m1_x2p = fixdenorm(m_R_m1_x_246);
			t_sample R_m1_y1p = fixdenorm(m_R_m1_y_245);
			t_sample R_m1_y2p = fixdenorm(m_R_m1_y_244);
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_246 = R_m1_x1p;
			m_R_m1_x_52 = R_rest;
			m_R_m1_y_244 = R_m1_y1p;
			m_R_m1_y_245 = R_mid_s1;
			t_sample R_m2_x1p = fixdenorm(m_R_m2_x_50);
			t_sample R_m2_x2p = fixdenorm(m_R_m2_x_243);
			t_sample R_m2_y1p = fixdenorm(m_R_m2_y_242);
			t_sample R_m2_y2p = fixdenorm(m_R_m2_y_241);
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_243 = R_m2_x1p;
			m_R_m2_x_50 = R_mid_s1;
			m_R_m2_y_241 = R_m2_y1p;
			m_R_m2_y_242 = R_mid;
			t_sample R_u1_x1p = fixdenorm(m_R_u1_x_48);
			t_sample R_u1_x2p = fixdenorm(m_R_u1_x_240);
			t_sample R_u1_y1p = fixdenorm(m_R_u1_y_239);
			t_sample R_u1_y2p = fixdenorm(m_R_u1_y_238);
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_240 = R_u1_x1p;
			m_R_u1_x_48 = R_rest;
			m_R_u1_y_238 = R_u1_y1p;
			m_R_u1_y_239 = R_high_s1;
			t_sample R_u2_x1p = fixdenorm(m_R_u2_x_46);
			t_sample R_u2_x2p = fixdenorm(m_R_u2_x_237);
			t_sample R_u2_y1p = fixdenorm(m_R_u2_y_236);
			t_sample R_u2_y2p = fixdenorm(m_R_u2_y_235);
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_237 = R_u2_x1p;
			m_R_u2_x_46 = R_high_s1;
			m_R_u2_y_235 = R_u2_y1p;
			m_R_u2_y_236 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_352 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_352) ? maxb_352 : ((int)0));
			t_sample maxb_353 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_353) ? maxb_353 : ((int)0));
			t_sample maxb_354 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_354) ? maxb_354 : ((int)0));
			t_sample maxb_355 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_355) ? maxb_355 : ((t_sample)1e-09));
			t_sample wLow_653 = safediv(wLow, wSum);
			t_sample wMid_654 = safediv(wMid, wSum);
			t_sample wHigh_655 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_653 * lowL) + (wMid_654 * midL)) + (wHigh_655 * highL));
			t_sample preBandR = (((wLow_653 * lowR) + (wMid_654 * midR)) + (wHigh_655 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			int soloOn = ((wBandSolo > ((t_sample)0.5)) * (scSm > ((t_sample)0.5)));
			t_sample iffalse_356 = (sumBandsL - preBandL);
			t_sample bypassWhenActiveL = (soloOn ? ((int)0) : iffalse_356);
			t_sample iffalse_357 = (sumBandsR - preBandR);
			t_sample bypassWhenActiveR = (soloOn ? ((int)0) : iffalse_357);
			t_sample mix_781 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_781;
			t_sample mix_782 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_782;
			t_sample L_loF_656 = smoothHpfFreq;
			t_sample L_hiF_657 = smoothLpfFreq;
			t_sample L_x_658 = lIn;
			t_sample maxb_359 = ((minb_358 < L_loF_656) ? minb_358 : L_loF_656);
			t_sample L_loF_661 = ((((int)10) < maxb_359) ? maxb_359 : ((int)10));
			t_sample maxb_361 = ((minb_360 < L_hiF_657) ? minb_360 : L_hiF_657);
			t_sample L_hiFr_662 = ((((int)10) < maxb_361) ? maxb_361 : ((int)10));
			t_sample maxb_362 = (L_loF_661 + ((int)1));
			t_sample L_hiF_663 = ((L_hiFr_662 < maxb_362) ? maxb_362 : L_hiFr_662);
			t_sample L_w0_lo_664 = safediv((((t_sample)6.2831853071796) * L_loF_661), L_sr_660);
			t_sample L_cos_lo_665 = cos(L_w0_lo_664);
			t_sample L_sin_lo_666 = sin(L_w0_lo_664);
			t_sample L_alpha_lo_667 = (L_sin_lo_666 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_668 = (((int)1) + L_alpha_lo_667);
			t_sample L_a1_lo_669 = (((int)-2) * L_cos_lo_665);
			t_sample L_a2_lo_670 = (((int)1) - L_alpha_lo_667);
			t_sample L_lp_b0_l_671 = safediv(((((int)1) - L_cos_lo_665) * ((t_sample)0.5)), L_a0_lo_668);
			t_sample L_lp_b1_l_672 = safediv((((int)1) - L_cos_lo_665), L_a0_lo_668);
			t_sample L_lp_b2_l_673 = L_lp_b0_l_671;
			t_sample L_lp_a1_l_674 = safediv(L_a1_lo_669, L_a0_lo_668);
			t_sample L_lp_a2_l_675 = safediv(L_a2_lo_670, L_a0_lo_668);
			t_sample L_hp_b0_l_676 = safediv(((((int)1) + L_cos_lo_665) * ((t_sample)0.5)), L_a0_lo_668);
			t_sample L_hp_b1_l_677 = safediv((-(((int)1) + L_cos_lo_665)), L_a0_lo_668);
			t_sample L_hp_b2_l_678 = L_hp_b0_l_676;
			t_sample L_hp_a1_l_679 = L_lp_a1_l_674;
			t_sample L_hp_a2_l_680 = L_lp_a2_l_675;
			t_sample L_w0_hi_681 = safediv((((t_sample)6.2831853071796) * L_hiF_663), L_sr_660);
			t_sample L_cos_hi_682 = cos(L_w0_hi_681);
			t_sample L_sin_hi_683 = sin(L_w0_hi_681);
			t_sample L_alpha_hi_684 = (L_sin_hi_683 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_685 = (((int)1) + L_alpha_hi_684);
			t_sample L_a1_hi_686 = (((int)-2) * L_cos_hi_682);
			t_sample L_a2_hi_687 = (((int)1) - L_alpha_hi_684);
			t_sample L_lp_b0_h_688 = safediv(((((int)1) - L_cos_hi_682) * ((t_sample)0.5)), L_a0_hi_685);
			t_sample L_lp_b1_h_689 = safediv((((int)1) - L_cos_hi_682), L_a0_hi_685);
			t_sample L_lp_b2_h_690 = L_lp_b0_h_688;
			t_sample L_lp_a1_h_691 = safediv(L_a1_hi_686, L_a0_hi_685);
			t_sample L_lp_a2_h_692 = safediv(L_a2_hi_687, L_a0_hi_685);
			t_sample L_hp_b0_h_693 = safediv(((((int)1) + L_cos_hi_682) * ((t_sample)0.5)), L_a0_hi_685);
			t_sample L_hp_b1_h_694 = safediv((-(((int)1) + L_cos_hi_682)), L_a0_hi_685);
			t_sample L_hp_b2_h_695 = L_hp_b0_h_693;
			t_sample L_hp_a1_h_696 = L_lp_a1_h_691;
			t_sample L_hp_a2_h_697 = L_lp_a2_h_692;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_37;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_282;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_281;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_280;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_671 * L_x_658) + (L_lp_b1_l_672 * L_ap1_lp1_x1p)) + (L_lp_b2_l_673 * L_ap1_lp1_x2p)) - (L_lp_a1_l_674 * L_ap1_lp1_y1p)) - (L_lp_a2_l_675 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_282 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_37 = L_x_658;
			m_L_ap1_lp1_y_280 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_281 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_35;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_279;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_278;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_277;
			t_sample L_ap1_lp = (((((L_lp_b0_l_671 * L_ap1_lp_s1) + (L_lp_b1_l_672 * L_ap1_lp2_x1p)) + (L_lp_b2_l_673 * L_ap1_lp2_x2p)) - (L_lp_a1_l_674 * L_ap1_lp2_y1p)) - (L_lp_a2_l_675 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_279 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_35 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_277 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_278 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_33;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_276;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_275;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_274;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_676 * L_x_658) + (L_hp_b1_l_677 * L_ap1_hp1_x1p)) + (L_hp_b2_l_678 * L_ap1_hp1_x2p)) - (L_hp_a1_l_679 * L_ap1_hp1_y1p)) - (L_hp_a2_l_680 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_276 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_33 = L_x_658;
			m_L_ap1_hp1_y_274 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_275 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_31;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_273;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_272;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_271;
			t_sample L_ap1_hp = (((((L_hp_b0_l_676 * L_ap1_hp_s1) + (L_hp_b1_l_677 * L_ap1_hp2_x1p)) + (L_hp_b2_l_678 * L_ap1_hp2_x2p)) - (L_hp_a1_l_679 * L_ap1_hp2_y1p)) - (L_hp_a2_l_680 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_273 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_31 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_271 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_272 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_29;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_270;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_269;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_268;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_688 * L_stage1_out) + (L_lp_b1_h_689 * L_ap2_lp1_x1p)) + (L_lp_b2_h_690 * L_ap2_lp1_x2p)) - (L_lp_a1_h_691 * L_ap2_lp1_y1p)) - (L_lp_a2_h_692 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_270 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_29 = L_stage1_out;
			m_L_ap2_lp1_y_268 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_269 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_27;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_267;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_266;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_265;
			t_sample L_ap2_lp = (((((L_lp_b0_h_688 * L_ap2_lp_s1) + (L_lp_b1_h_689 * L_ap2_lp2_x1p)) + (L_lp_b2_h_690 * L_ap2_lp2_x2p)) - (L_lp_a1_h_691 * L_ap2_lp2_y1p)) - (L_lp_a2_h_692 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_267 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_27 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_265 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_266 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_25;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_264;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_263;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_262;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_693 * L_stage1_out) + (L_hp_b1_h_694 * L_ap2_hp1_x1p)) + (L_hp_b2_h_695 * L_ap2_hp1_x2p)) - (L_hp_a1_h_696 * L_ap2_hp1_y1p)) - (L_hp_a2_h_697 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_264 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_25 = L_stage1_out;
			m_L_ap2_hp1_y_262 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_263 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_23;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_261;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_260;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_259;
			t_sample L_ap2_hp = (((((L_hp_b0_h_693 * L_ap2_hp_s1) + (L_hp_b1_h_694 * L_ap2_hp2_x1p)) + (L_hp_b2_h_695 * L_ap2_hp2_x2p)) - (L_hp_a1_h_696 * L_ap2_hp2_y1p)) - (L_hp_a2_h_697 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_261 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_23 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_259 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_260 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_698 = smoothHpfFreq;
			t_sample R_hiF_699 = smoothLpfFreq;
			t_sample R_x_700 = rIn;
			t_sample maxb_364 = ((minb_363 < R_loF_698) ? minb_363 : R_loF_698);
			t_sample R_loF_703 = ((((int)10) < maxb_364) ? maxb_364 : ((int)10));
			t_sample maxb_366 = ((minb_365 < R_hiF_699) ? minb_365 : R_hiF_699);
			t_sample R_hiFr_704 = ((((int)10) < maxb_366) ? maxb_366 : ((int)10));
			t_sample maxb_367 = (R_loF_703 + ((int)1));
			t_sample R_hiF_705 = ((R_hiFr_704 < maxb_367) ? maxb_367 : R_hiFr_704);
			t_sample R_w0_lo_706 = safediv((((t_sample)6.2831853071796) * R_loF_703), R_sr_702);
			t_sample R_cos_lo_707 = cos(R_w0_lo_706);
			t_sample R_sin_lo_708 = sin(R_w0_lo_706);
			t_sample R_alpha_lo_709 = (R_sin_lo_708 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_710 = (((int)1) + R_alpha_lo_709);
			t_sample R_a1_lo_711 = (((int)-2) * R_cos_lo_707);
			t_sample R_a2_lo_712 = (((int)1) - R_alpha_lo_709);
			t_sample R_lp_b0_l_713 = safediv(((((int)1) - R_cos_lo_707) * ((t_sample)0.5)), R_a0_lo_710);
			t_sample R_lp_b1_l_714 = safediv((((int)1) - R_cos_lo_707), R_a0_lo_710);
			t_sample R_lp_b2_l_715 = R_lp_b0_l_713;
			t_sample R_lp_a1_l_716 = safediv(R_a1_lo_711, R_a0_lo_710);
			t_sample R_lp_a2_l_717 = safediv(R_a2_lo_712, R_a0_lo_710);
			t_sample R_hp_b0_l_718 = safediv(((((int)1) + R_cos_lo_707) * ((t_sample)0.5)), R_a0_lo_710);
			t_sample R_hp_b1_l_719 = safediv((-(((int)1) + R_cos_lo_707)), R_a0_lo_710);
			t_sample R_hp_b2_l_720 = R_hp_b0_l_718;
			t_sample R_hp_a1_l_721 = R_lp_a1_l_716;
			t_sample R_hp_a2_l_722 = R_lp_a2_l_717;
			t_sample R_w0_hi_723 = safediv((((t_sample)6.2831853071796) * R_hiF_705), R_sr_702);
			t_sample R_cos_hi_724 = cos(R_w0_hi_723);
			t_sample R_sin_hi_725 = sin(R_w0_hi_723);
			t_sample R_alpha_hi_726 = (R_sin_hi_725 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_727 = (((int)1) + R_alpha_hi_726);
			t_sample R_a1_hi_728 = (((int)-2) * R_cos_hi_724);
			t_sample R_a2_hi_729 = (((int)1) - R_alpha_hi_726);
			t_sample R_lp_b0_h_730 = safediv(((((int)1) - R_cos_hi_724) * ((t_sample)0.5)), R_a0_hi_727);
			t_sample R_lp_b1_h_731 = safediv((((int)1) - R_cos_hi_724), R_a0_hi_727);
			t_sample R_lp_b2_h_732 = R_lp_b0_h_730;
			t_sample R_lp_a1_h_733 = safediv(R_a1_hi_728, R_a0_hi_727);
			t_sample R_lp_a2_h_734 = safediv(R_a2_hi_729, R_a0_hi_727);
			t_sample R_hp_b0_h_735 = safediv(((((int)1) + R_cos_hi_724) * ((t_sample)0.5)), R_a0_hi_727);
			t_sample R_hp_b1_h_736 = safediv((-(((int)1) + R_cos_hi_724)), R_a0_hi_727);
			t_sample R_hp_b2_h_737 = R_hp_b0_h_735;
			t_sample R_hp_a1_h_738 = R_lp_a1_h_733;
			t_sample R_hp_a2_h_739 = R_lp_a2_h_734;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_36;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_222;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_221;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_220;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_713 * R_x_700) + (R_lp_b1_l_714 * R_ap1_lp1_x1p)) + (R_lp_b2_l_715 * R_ap1_lp1_x2p)) - (R_lp_a1_l_716 * R_ap1_lp1_y1p)) - (R_lp_a2_l_717 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_222 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_36 = R_x_700;
			m_R_ap1_lp1_y_220 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_221 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_34;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_219;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_218;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_217;
			t_sample R_ap1_lp = (((((R_lp_b0_l_713 * R_ap1_lp_s1) + (R_lp_b1_l_714 * R_ap1_lp2_x1p)) + (R_lp_b2_l_715 * R_ap1_lp2_x2p)) - (R_lp_a1_l_716 * R_ap1_lp2_y1p)) - (R_lp_a2_l_717 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_219 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_34 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_217 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_218 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_32;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_216;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_215;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_214;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_718 * R_x_700) + (R_hp_b1_l_719 * R_ap1_hp1_x1p)) + (R_hp_b2_l_720 * R_ap1_hp1_x2p)) - (R_hp_a1_l_721 * R_ap1_hp1_y1p)) - (R_hp_a2_l_722 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_216 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_32 = R_x_700;
			m_R_ap1_hp1_y_214 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_215 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_30;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_213;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_212;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_211;
			t_sample R_ap1_hp = (((((R_hp_b0_l_718 * R_ap1_hp_s1) + (R_hp_b1_l_719 * R_ap1_hp2_x1p)) + (R_hp_b2_l_720 * R_ap1_hp2_x2p)) - (R_hp_a1_l_721 * R_ap1_hp2_y1p)) - (R_hp_a2_l_722 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_213 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_30 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_211 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_212 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_28;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_210;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_209;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_208;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_730 * R_stage1_out) + (R_lp_b1_h_731 * R_ap2_lp1_x1p)) + (R_lp_b2_h_732 * R_ap2_lp1_x2p)) - (R_lp_a1_h_733 * R_ap2_lp1_y1p)) - (R_lp_a2_h_734 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_210 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_28 = R_stage1_out;
			m_R_ap2_lp1_y_208 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_209 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_26;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_207;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_206;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_205;
			t_sample R_ap2_lp = (((((R_lp_b0_h_730 * R_ap2_lp_s1) + (R_lp_b1_h_731 * R_ap2_lp2_x1p)) + (R_lp_b2_h_732 * R_ap2_lp2_x2p)) - (R_lp_a1_h_733 * R_ap2_lp2_y1p)) - (R_lp_a2_h_734 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_207 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_26 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_205 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_206 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_24;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_204;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_203;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_202;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_735 * R_stage1_out) + (R_hp_b1_h_736 * R_ap2_hp1_x1p)) + (R_hp_b2_h_737 * R_ap2_hp1_x2p)) - (R_hp_a1_h_738 * R_ap2_hp1_y1p)) - (R_hp_a2_h_739 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_204 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_24 = R_stage1_out;
			m_R_ap2_hp1_y_202 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_203 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_22;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_201;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_200;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_199;
			t_sample R_ap2_hp = (((((R_hp_b0_h_735 * R_ap2_hp_s1) + (R_hp_b1_h_736 * R_ap2_hp2_x1p)) + (R_hp_b2_h_737 * R_ap2_hp2_x2p)) - (R_hp_a1_h_738 * R_ap2_hp2_y1p)) - (R_hp_a2_h_739 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_201 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_22 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_199 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_200 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_783 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample dryL = mix_783;
			t_sample mix_784 = (rIn + (scSm * (dryCompR - rIn)));
			t_sample dryR = mix_784;
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
			t_sample lLs_740 = (((((a0Ls * lFiltered) + (a1Ls * fixdenorm(m_tiltLsL_93))) + (a2Ls * fixdenorm(m_tiltLsL_94))) - (b1Ls * fixdenorm(m_tiltLsL_91))) - (b2Ls * fixdenorm(m_tiltLsL_92)));
			m_tiltLsL_94 = m_tiltLsL_93;
			m_tiltLsL_93 = lFiltered;
			m_tiltLsL_92 = m_tiltLsL_91;
			m_tiltLsL_91 = lLs_740;
			t_sample rLs_741 = (((((a0Ls * rFiltered) + (a1Ls * fixdenorm(m_tiltLsR_89))) + (a2Ls * fixdenorm(m_tiltLsR_90))) - (b1Ls * fixdenorm(m_tiltLsR_87))) - (b2Ls * fixdenorm(m_tiltLsR_88)));
			m_tiltLsR_90 = m_tiltLsR_89;
			m_tiltLsR_89 = rFiltered;
			m_tiltLsR_88 = m_tiltLsR_87;
			m_tiltLsR_87 = rLs_741;
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
			t_sample lTiltRaw = (((((a0Hs * lLs_740) + (a1Hs * fixdenorm(m_tiltHsL_85))) + (a2Hs * fixdenorm(m_tiltHsL_86))) - (b1Hs * fixdenorm(m_tiltHsL_83))) - (b2Hs * fixdenorm(m_tiltHsL_84)));
			m_tiltHsL_86 = m_tiltHsL_85;
			m_tiltHsL_85 = lLs_740;
			m_tiltHsL_84 = m_tiltHsL_83;
			m_tiltHsL_83 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_741) + (a1Hs * fixdenorm(m_tiltHsR_81))) + (a2Hs * fixdenorm(m_tiltHsR_82))) - (b1Hs * fixdenorm(m_tiltHsR_79))) - (b2Hs * fixdenorm(m_tiltHsR_80)));
			m_tiltHsR_82 = m_tiltHsR_81;
			m_tiltHsR_81 = rLs_741;
			m_tiltHsR_80 = m_tiltHsR_79;
			m_tiltHsR_79 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cosw)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sinw) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cosw)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sinw) + (b2Ls * sin2)));
			t_sample maxb_368 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_368) ? maxb_368 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cosw)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sinw) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cosw)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sinw) + (b2Hs * sin2)));
			t_sample maxb_369 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_369) ? maxb_369 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_370 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_370) ? maxb_370 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample mode = smoothedMode;
			t_sample maxb_371 = (((int)1) - fabs((mode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_371) ? maxb_371 : ((int)0));
			t_sample maxb_372 = (((int)1) - fabs((mode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_372) ? maxb_372 : ((int)0));
			t_sample maxb_373 = (((int)1) - fabs((mode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_373) ? maxb_373 : ((int)0));
			t_sample maxb_374 = (((int)1) - fabs((mode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_374) ? maxb_374 : ((int)0));
			t_sample maxb_375 = (((int)1) - fabs((mode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_375) ? maxb_375 : ((int)0));
			t_sample maxb_376 = (((int)1) - fabs((mode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_376) ? maxb_376 : ((int)0));
			t_sample maxb_377 = (((int)1) - fabs((mode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_377) ? maxb_377 : ((int)0));
			t_sample maxb_378 = (((int)1) - fabs((mode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_378) ? maxb_378 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_742 = safediv(w0, sumWeights);
			t_sample w_743 = safediv(w1, sumWeights);
			t_sample w_744 = safediv(w2, sumWeights);
			t_sample w_745 = safediv(w3, sumWeights);
			t_sample w_746 = safediv(w4, sumWeights);
			t_sample w_747 = safediv(w5, sumWeights);
			t_sample w_748 = safediv(w6, sumWeights);
			t_sample w_749 = safediv(w7, sumWeights);
			t_sample dcNorm = ((m_hDc_116 * ((int)2)) - ((int)1));
			t_sample dcSkew = (tanh((dcNorm * ((int)3))) * ((t_sample)0.4));
			t_sample return_387;
			t_sample return_388;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_387, return_388);
			t_sample softL_A = return_387;
			t_sample softR_A = return_388;
			t_sample return_399;
			t_sample return_400;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_399, return_400);
			t_sample sigmL_A = return_399;
			t_sample sigmR_A = return_400;
			t_sample return_409;
			t_sample return_410;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_409, return_410);
			t_sample rectL_A = return_409;
			t_sample rectR_A = return_410;
			t_sample return_419;
			t_sample return_420;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_419, return_420);
			t_sample fuzz1L_A = return_419;
			t_sample fuzz1R_A = return_420;
			t_sample return_435;
			t_sample return_436;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_435, return_436);
			t_sample tanhL_A = return_435;
			t_sample tanhR_A = return_436;
			t_sample return_443;
			t_sample return_444;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_443, return_444);
			t_sample recthL_A = return_443;
			t_sample recthR_A = return_444;
			t_sample return_451;
			t_sample return_452;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_451, return_452);
			t_sample atanL_A = return_451;
			t_sample atanR_A = return_452;
			t_sample return_467;
			t_sample return_468;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_467, return_468);
			t_sample hardL_A = return_467;
			t_sample hardR_A = return_468;
			t_sample distL_A = ((((((((softL_A * w_742) + (sigmL_A * w_743)) + (rectL_A * w_744)) + (fuzz1L_A * w_745)) + (tanhL_A * w_746)) + (recthL_A * w_747)) + (atanL_A * w_748)) + (hardL_A * w_749));
			t_sample distR_A = ((((((((softR_A * w_742) + (sigmR_A * w_743)) + (rectR_A * w_744)) + (fuzz1R_A * w_745)) + (tanhR_A * w_746)) + (recthR_A * w_747)) + (atanR_A * w_748)) + (hardR_A * w_749));
			t_sample preOutL = __m_dcblock_469(distL_A);
			t_sample preOutR = __m_dcblock_470(distR_A);
			t_sample return_471;
			t_sample return_472;
			softclip_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_471, return_472);
			t_sample softL_B = return_471;
			t_sample softR_B = return_472;
			t_sample return_473;
			t_sample return_474;
			sigmoid_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_473, return_474);
			t_sample sigmL_B = return_473;
			t_sample sigmR_B = return_474;
			t_sample return_475;
			t_sample return_476;
			rectF_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_475, return_476);
			t_sample rectL_B = return_475;
			t_sample rectR_B = return_476;
			t_sample return_477;
			t_sample return_478;
			fuzzExp1_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_477, return_478);
			t_sample fuzz1L_B = return_477;
			t_sample fuzz1R_B = return_478;
			t_sample return_479;
			t_sample return_480;
			tangenteHiperbolica_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_479, return_480);
			t_sample tanhL_B = return_479;
			t_sample tanhR_B = return_480;
			t_sample return_481;
			t_sample return_482;
			rectH_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_481, return_482);
			t_sample recthL_B = return_481;
			t_sample recthR_B = return_482;
			t_sample return_483;
			t_sample return_484;
			arctangent_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_483, return_484);
			t_sample atanL_B = return_483;
			t_sample atanR_B = return_484;
			t_sample return_485;
			t_sample return_486;
			hardClip_d_d_d_d_d(preDistInL, preDistInR, drive, dcSkew, ceiling, return_485, return_486);
			t_sample hardL_B = return_485;
			t_sample hardR_B = return_486;
			t_sample distL_B = ((((((((softL_B * w_742) + (sigmL_B * w_743)) + (rectL_B * w_744)) + (fuzz1L_B * w_745)) + (tanhL_B * w_746)) + (recthL_B * w_747)) + (atanL_B * w_748)) + (hardL_B * w_749));
			t_sample distR_B = ((((((((softR_B * w_742) + (sigmR_B * w_743)) + (rectR_B * w_744)) + (fuzz1R_B * w_745)) + (tanhR_B * w_746)) + (recthR_B * w_747)) + (atanR_B * w_748)) + (hardR_B * w_749));
			t_sample postInL = __m_dcblock_487(distL_B);
			t_sample postInR = __m_dcblock_488(distR_B);
			t_sample postLsL = (((((a0Ls * postInL) + (a1Ls * m_postTiltLsL_76)) + (a2Ls * m_postTiltLsL_77)) - (b1Ls * m_postTiltLsL_74)) - (b2Ls * m_postTiltLsL_75));
			m_postTiltLsL_77 = m_postTiltLsL_76;
			m_postTiltLsL_76 = postInL;
			m_postTiltLsL_75 = m_postTiltLsL_74;
			m_postTiltLsL_74 = postLsL;
			t_sample postLsR = (((((a0Ls * postInR) + (a1Ls * m_postTiltLsR_72)) + (a2Ls * m_postTiltLsR_73)) - (b1Ls * m_postTiltLsR_70)) - (b2Ls * m_postTiltLsR_71));
			m_postTiltLsR_73 = m_postTiltLsR_72;
			m_postTiltLsR_72 = postInR;
			m_postTiltLsR_71 = m_postTiltLsR_70;
			m_postTiltLsR_70 = postLsR;
			t_sample postTiltRawL = (((((a0Hs * postLsL) + (a1Hs * m_postTiltHsL_68)) + (a2Hs * m_postTiltHsL_69)) - (b1Hs * m_postTiltHsL_66)) - (b2Hs * m_postTiltHsL_67));
			m_postTiltHsL_69 = m_postTiltHsL_68;
			m_postTiltHsL_68 = postLsL;
			m_postTiltHsL_67 = m_postTiltHsL_66;
			m_postTiltHsL_66 = postTiltRawL;
			t_sample postTiltRawR = (((((a0Hs * postLsR) + (a1Hs * m_postTiltHsR_64)) + (a2Hs * m_postTiltHsR_65)) - (b1Hs * m_postTiltHsR_62)) - (b2Hs * m_postTiltHsR_63));
			m_postTiltHsR_65 = m_postTiltHsR_64;
			m_postTiltHsR_64 = postLsR;
			m_postTiltHsR_63 = m_postTiltHsR_62;
			m_postTiltHsR_62 = postTiltRawR;
			t_sample postTiltL = (postTiltRawL * gPivot);
			t_sample postTiltR = (postTiltRawR * gPivot);
			t_sample mix_785 = (preOutL + (wPost * (postTiltL - preOutL)));
			t_sample distMorphL = mix_785;
			t_sample mix_786 = (preOutR + (wPost * (postTiltR - preOutR)));
			t_sample distMorphR = mix_786;
			t_sample cleanPreTiltL = lTilt;
			t_sample cleanPreTiltR = rTilt;
			t_sample mix_787 = (cleanPreTiltL + (wDist * (distMorphL - cleanPreTiltL)));
			t_sample processedL = mix_787;
			t_sample mix_788 = (cleanPreTiltR + (wDist * (distMorphR - cleanPreTiltR)));
			t_sample processedR = mix_788;
			t_sample return_489;
			t_sample return_490;
			bitCrusher_d_d_d(processedL, processedR, bits, return_489, return_490);
			t_sample bitL = return_489;
			t_sample bitR = return_490;
			t_sample bcL = __m_dcblock_491(bitL);
			t_sample bcR = __m_dcblock_492(bitR);
			t_sample mix_789 = (processedL + (bitson * (bcL - processedL)));
			t_sample withBitCrusherL = mix_789;
			t_sample mix_790 = (processedR + (bitson * (bcR - processedR)));
			t_sample withBitCrusherR = mix_790;
			t_sample maxb_493 = floor((m_hDownsample_108 + ((int)1)));
			t_sample deciFactor = ((((int)1) < maxb_493) ? maxb_493 : ((int)1));
			int enableNow = (downsampleOn > ((t_sample)0.5));
			int enableEdge = (enableNow > m_dsEnablePrev_95);
			m_dsEnablePrev_95 = enableNow;
			t_sample inc = safediv(((int)1), deciFactor);
			t_sample iffalse_494 = (m_dsPhase_97 + inc);
			m_dsPhase_97 = (enableEdge ? ((int)0) : iffalse_494);
			m_dsPhase_97 = (m_dsPhase_97 - floor(m_dsPhase_97));
			int dsEdgeWrap = (m_dsPhase_97 < m_dsTrigPrev_96);
			int dsEdge = (((enableEdge + dsEdgeWrap) + (deciFactor == ((int)1))) > ((t_sample)0.5));
			m_dsTrigPrev_96 = m_dsPhase_97;
			__m_latch_495 = ((dsEdge != 0) ? withBitCrusherL : __m_latch_495);
			t_sample dsHeldL = __m_latch_495;
			__m_latch_496 = ((dsEdge != 0) ? withBitCrusherR : __m_latch_496);
			t_sample dsHeldR = __m_latch_496;
			t_sample mix_791 = (withBitCrusherL + (downsampleOn * (dsHeldL - withBitCrusherL)));
			t_sample wetFinalL = mix_791;
			t_sample mix_792 = (withBitCrusherR + (downsampleOn * (dsHeldR - withBitCrusherR)));
			t_sample wetFinalR = mix_792;
			t_sample wetWithMakeupL = ((wetFinalL * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((wetFinalR * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample omegaT = safediv((toneFreq * ((t_sample)6.2831853071796)), samplerate);
			t_sample sinT = sin(omegaT);
			t_sample cosT = cos(omegaT);
			t_sample alphaT = (sinT * ((t_sample)0.70710678118655));
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
			t_sample tL_x1p = fixdenorm(m_toneL_x_16);
			t_sample tL_x2p = fixdenorm(m_toneL_x_15);
			t_sample tL_y1p = fixdenorm(m_toneL_y_14);
			t_sample tL_y2p = fixdenorm(m_toneL_y_13);
			t_sample wetToneL = (((((t_a0 * wetWithMakeupL) + (t_a1 * tL_x1p)) + (t_a2 * tL_x2p)) - (t_b1 * tL_y1p)) - (t_b2 * tL_y2p));
			m_toneL_x_15 = tL_x1p;
			m_toneL_x_16 = wetWithMakeupL;
			m_toneL_y_13 = tL_y1p;
			m_toneL_y_14 = wetToneL;
			t_sample tR_x1p = fixdenorm(m_toneR_x_12);
			t_sample tR_x2p = fixdenorm(m_toneR_x_11);
			t_sample tR_y1p = fixdenorm(m_toneR_y_10);
			t_sample tR_y2p = fixdenorm(m_toneR_y_9);
			t_sample wetToneR = (((((t_a0 * wetWithMakeupR) + (t_a1 * tR_x1p)) + (t_a2 * tR_x2p)) - (t_b1 * tR_y1p)) - (t_b2 * tR_y2p));
			m_toneR_x_11 = tR_x1p;
			m_toneR_x_12 = wetWithMakeupR;
			m_toneR_y_9 = tR_y1p;
			m_toneR_y_10 = wetToneR;
			t_sample mix_793 = (wetWithMakeupL + (toneOn * (wetToneL - wetWithMakeupL)));
			t_sample mix_794 = (wetWithMakeupR + (toneOn * (wetToneR - wetWithMakeupR)));
			t_sample apL_x1p = fixdenorm(m_toneApL_x_8);
			t_sample apL_x2p = fixdenorm(m_toneApL_x_7);
			t_sample apL_y1p = fixdenorm(m_toneApL_y_6);
			t_sample apL_y2p = fixdenorm(m_toneApL_y_5);
			t_sample dryCompL_750 = (((((ap_b0 * dryL) + (ap_b1 * apL_x1p)) + (((int)1) * apL_x2p)) - (ap_a1 * apL_y1p)) - (ap_a2 * apL_y2p));
			m_toneApL_x_7 = apL_x1p;
			m_toneApL_x_8 = dryL;
			m_toneApL_y_5 = apL_y1p;
			m_toneApL_y_6 = dryCompL_750;
			t_sample apR_x1p = fixdenorm(m_toneApR_x_4);
			t_sample apR_x2p = fixdenorm(m_toneApR_x_3);
			t_sample apR_y1p = fixdenorm(m_toneApR_y_2);
			t_sample apR_y2p = fixdenorm(m_toneApR_y_1);
			t_sample dryCompR_751 = (((((ap_b0 * dryR) + (ap_b1 * apR_x1p)) + (((int)1) * apR_x2p)) - (ap_a1 * apR_y1p)) - (ap_a2 * apR_y2p));
			m_toneApR_x_3 = apR_x1p;
			m_toneApR_x_4 = dryR;
			m_toneApR_y_1 = apR_y1p;
			m_toneApR_y_2 = dryCompR_751;
			t_sample mix_795 = (dryL + (toneOn * (dryCompL_750 - dryL)));
			t_sample mix_796 = (dryR + (toneOn * (dryCompR_751 - dryR)));
			t_sample mix_797 = (mix_795 + (drywet * (mix_793 - mix_795)));
			t_sample mix_798 = (mix_796 + (drywet * (mix_794 - mix_796)));
			t_sample clamp_800 = ((mix_797 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_797 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_797));
			t_sample mix_799 = (mix_797 + (safeOn * (clamp_800 - mix_797)));
			t_sample clamp_802 = ((mix_798 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_798 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_798));
			t_sample mix_801 = (mix_798 + (safeOn * (clamp_802 - mix_798)));
			t_sample mix_803 = (lIn + (bypass * (mix_799 - lIn)));
			t_sample mix_804 = (rIn + (bypass * (mix_801 - rIn)));
			t_sample out1 = mix_803;
			t_sample out3 = ((int)0);
			t_sample out5 = rTrimmed;
			t_sample out4 = lTrimmed;
			t_sample out2 = mix_804;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_r_TONEFREQ(t_param _value) {
		m_r_TONEFREQ_319 = (_value < 5000 ? 5000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_q_TONEON(t_param _value) {
		m_q_TONEON_320 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_SAFELIMITON(t_param _value) {
		m_p_SAFELIMITON_321 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_BANDSOLO(t_param _value) {
		m_p_BANDSOLO_322 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_DISTON(t_param _value) {
		m_p_DISTON_323 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_TILTPOS(t_param _value) {
		m_p_TILTPOS_324 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_325 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_326 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_327 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_328 = (_value < -24 ? -24 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_329 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_330 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_331 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_332 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_333 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_334 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_335 = (_value < 2 ? 2 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_336 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_337 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_338 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_339 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_340 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_341 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void softclip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_379 = (inl >= ((int)0));
		t_sample iftrue_380 = (inl * lDrivePos);
		t_sample iffalse_381 = (inl * lDriveNeg);
		t_sample lNorm = safediv((cond_379 ? iftrue_380 : iffalse_381), cell);
		int cond_382 = (inr >= ((int)0));
		t_sample iftrue_383 = (inr * rDrivePos);
		t_sample iffalse_384 = (inr * rDriveNeg);
		t_sample rNorm = safediv((cond_382 ? iftrue_383 : iffalse_384), cell);
		t_sample lCubic = (lNorm - (((lNorm * lNorm) * lNorm) * ((t_sample)0.33333333333333)));
		t_sample rCubic = (rNorm - (((rNorm * rNorm) * rNorm) * ((t_sample)0.33333333333333)));
		t_sample lLimited = (((lNorm > 0) ? 1 : ((lNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		t_sample rLimited = (((rNorm > 0) ? 1 : ((rNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		int cond_385 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_385 ? lCubic : lLimited);
		int cond_386 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_386 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_389 = (inl >= ((int)0));
		t_sample iftrue_390 = (inl * lDrivePos);
		t_sample iffalse_391 = (inl * lDriveNeg);
		t_sample lAdj = (cond_389 ? iftrue_390 : iffalse_391);
		int cond_392 = (inr >= ((int)0));
		t_sample iftrue_393 = (inr * rDrivePos);
		t_sample iffalse_394 = (inr * rDriveNeg);
		t_sample rAdj = (cond_392 ? iftrue_393 : iffalse_394);
		int factor = (-((int)1));
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lAdj))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rAdj))))) - ((int)1));
		t_sample v_395 = (l * cell);
		t_sample min_396 = (-cell);
		t_sample lOut = ((v_395 <= min_396) ? min_396 : ((v_395 >= cell) ? cell : v_395));
		t_sample v_397 = (r * cell);
		t_sample min_398 = (-cell);
		t_sample rOut = ((v_397 <= min_398) ? min_398 : ((v_397 >= cell) ? cell : v_397));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_401 = (inl >= ((int)0));
		t_sample iftrue_402 = (inl * lDrivePos);
		t_sample iffalse_403 = (inl * lDriveNeg);
		t_sample lAdj = (cond_401 ? iftrue_402 : iffalse_403);
		int cond_404 = (inr >= ((int)0));
		t_sample iftrue_405 = (inr * rDrivePos);
		t_sample iffalse_406 = (inr * rDriveNeg);
		t_sample rAdj = (cond_404 ? iftrue_405 : iffalse_406);
		t_sample l = ((((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0)) * fabs(lAdj)) * ((t_sample)0.707));
		t_sample r = ((((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0)) * fabs(rAdj)) * ((t_sample)0.707));
		t_sample min_407 = (-cell);
		t_sample lOut = ((l <= min_407) ? min_407 : ((l >= cell) ? cell : l));
		t_sample min_408 = (-cell);
		t_sample rOut = ((r <= min_408) ? min_408 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_411 = (inl >= ((int)0));
		t_sample iftrue_412 = (inl * lDrivePos);
		t_sample iffalse_413 = (inl * lDriveNeg);
		t_sample lAdj = (cond_411 ? iftrue_412 : iffalse_413);
		int cond_414 = (inr >= ((int)0));
		t_sample iftrue_415 = (inr * rDrivePos);
		t_sample iffalse_416 = (inr * rDriveNeg);
		t_sample rAdj = (cond_414 ? iftrue_415 : iffalse_416);
		int signl = ((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0));
		int signr = ((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0));
		t_sample l = (signl * (((int)1) - exp((-fabs(lAdj)))));
		t_sample r = (signr * (((int)1) - exp((-fabs(rAdj)))));
		t_sample min_417 = (-cell);
		t_sample lOut = ((l <= min_417) ? min_417 : ((l >= cell) ? cell : l));
		t_sample min_418 = (-cell);
		t_sample rOut = ((r <= min_418) ? min_418 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_421 = (inl >= ((int)0));
		t_sample v_422 = (inl * lDrivePos);
		t_sample min_423 = (-cell);
		t_sample iftrue_424 = ((v_422 <= min_423) ? min_423 : ((v_422 >= cell) ? cell : v_422));
		t_sample v_425 = (inl * lDriveNeg);
		t_sample min_426 = (-cell);
		t_sample iffalse_427 = ((v_425 <= min_426) ? min_426 : ((v_425 >= cell) ? cell : v_425));
		t_sample l = (cond_421 ? iftrue_424 : iffalse_427);
		int cond_428 = (inr >= ((int)0));
		t_sample v_429 = (inr * rDrivePos);
		t_sample min_430 = (-cell);
		t_sample iftrue_431 = ((v_429 <= min_430) ? min_430 : ((v_429 >= cell) ? cell : v_429));
		t_sample v_432 = (inr * rDriveNeg);
		t_sample min_433 = (-cell);
		t_sample iffalse_434 = ((v_432 <= min_433) ? min_433 : ((v_432 >= cell) ? cell : v_432));
		t_sample r = (cond_428 ? iftrue_431 : iffalse_434);
		t_sample lOut = safediv(tanh(l), tanh(dr));
		t_sample rOut = safediv(tanh(r), tanh(dr));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectH_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample maxa_437 = (inl * lDrivePos);
		t_sample lPositive = ((maxa_437 < ((int)0)) ? ((int)0) : maxa_437);
		t_sample maxa_438 = (inr * rDrivePos);
		t_sample rPositive = ((maxa_438 < ((int)0)) ? ((int)0) : maxa_438);
		t_sample v_439 = (lPositive * ((t_sample)0.5));
		t_sample min_440 = (-cell);
		t_sample l = ((v_439 <= min_440) ? min_440 : ((v_439 >= cell) ? cell : v_439));
		t_sample v_441 = (rPositive * ((t_sample)0.5));
		t_sample min_442 = (-cell);
		t_sample r = ((v_441 <= min_442) ? min_442 : ((v_441 >= cell) ? cell : v_441));
		out1 = l;
		out2 = r;
		
	};
	inline void arctangent_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_445 = (inl >= ((int)0));
		t_sample iftrue_446 = (inl * lDrivePos);
		t_sample iffalse_447 = (inl * lDriveNeg);
		t_sample lAdj = (cond_445 ? iftrue_446 : iffalse_447);
		int cond_448 = (inr >= ((int)0));
		t_sample iftrue_449 = (inr * rDrivePos);
		t_sample iffalse_450 = (inr * rDriveNeg);
		t_sample rAdj = (cond_448 ? iftrue_449 : iffalse_450);
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
		int cond_453 = (inl >= ((int)0));
		t_sample iftrue_454 = (inl * lDrivePos);
		t_sample iffalse_455 = (inl * lDriveNeg);
		t_sample lDriven = (cond_453 ? iftrue_454 : iffalse_455);
		int cond_456 = (inr >= ((int)0));
		t_sample iftrue_457 = (inr * rDrivePos);
		t_sample iffalse_458 = (inr * rDriveNeg);
		t_sample rDriven = (cond_456 ? iftrue_457 : iffalse_458);
		int cond_459 = (lDriven > cell);
		int cond_460 = (lDriven < (-cell));
		t_sample iftrue_461 = (-cell);
		t_sample iffalse_462 = (cond_460 ? iftrue_461 : lDriven);
		t_sample l = (cond_459 ? cell : iffalse_462);
		int cond_463 = (rDriven > cell);
		int cond_464 = (rDriven < (-cell));
		t_sample iftrue_465 = (-cell);
		t_sample iffalse_466 = (cond_464 ? iftrue_465 : rDriven);
		t_sample r = (cond_463 ? cell : iffalse_466);
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
int num_params() { return 23; }

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
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_341; break;
		case 1: *value = self->m_b_DRIVE_340; break;
		case 2: *value = self->m_c_DC_339; break;
		case 3: *value = self->m_d_MODE_338; break;
		case 4: *value = self->m_e_CEILING_337; break;
		case 5: *value = self->m_f_BYPASS_336; break;
		case 6: *value = self->m_g_BITS_335; break;
		case 7: *value = self->m_h_BITSON_334; break;
		case 8: *value = self->m_i_TILT_333; break;
		case 9: *value = self->m_j_HPF_332; break;
		case 10: *value = self->m_k_INPUT_329; break;
		case 11: *value = self->m_k_LPF_331; break;
		case 12: *value = self->m_l_OUTPUT_328; break;
		case 13: *value = self->m_l_SC_330; break;
		case 14: *value = self->m_m_DOWNSAMPLE_327; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_326; break;
		case 16: *value = self->m_o_BAND_325; break;
		case 17: *value = self->m_p_BANDSOLO_322; break;
		case 18: *value = self->m_p_DISTON_323; break;
		case 19: *value = self->m_p_SAFELIMITON_321; break;
		case 20: *value = self->m_p_TILTPOS_324; break;
		case 21: *value = self->m_q_TONEON_320; break;
		case 22: *value = self->m_r_TONEFREQ_319; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(23 * sizeof(ParamInfo));
	self->__commonstate.numparams = 23;
	// initialize parameter 0 ("m_a_DRYWET_341")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_341;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_340")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_340;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_339")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_339;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_338")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_338;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_337")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_337;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_336")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_336;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_335")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_335;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 2;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_334")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_334;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_333")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_333;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_332")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_332;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_329")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_329;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_331")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_331;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_328")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_328;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -24;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_330")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_330;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_327")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_327;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_326")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_326;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_325")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_325;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_p_BANDSOLO_322")
	pi = self->__commonstate.params + 17;
	pi->name = "p_BANDSOLO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_BANDSOLO_322;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_p_DISTON_323")
	pi = self->__commonstate.params + 18;
	pi->name = "p_DISTON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_DISTON_323;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_p_SAFELIMITON_321")
	pi = self->__commonstate.params + 19;
	pi->name = "p_SAFELIMITON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_SAFELIMITON_321;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_p_TILTPOS_324")
	pi = self->__commonstate.params + 20;
	pi->name = "p_TILTPOS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_TILTPOS_324;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_q_TONEON_320")
	pi = self->__commonstate.params + 21;
	pi->name = "q_TONEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_TONEON_320;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_r_TONEFREQ_319")
	pi = self->__commonstate.params + 22;
	pi->name = "r_TONEFREQ";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_r_TONEFREQ_319;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 5000;
	pi->outputmax = 20000;
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
