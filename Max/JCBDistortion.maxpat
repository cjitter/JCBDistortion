{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 9,
			"minor" : 0,
			"revision" : 8,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 193.0, 87.0, 1688.0, 903.0 ],
		"gridsize" : [ 15.0, 15.0 ],
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 829.0, 13.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-65",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 829.0, 51.0, 79.0, 22.0 ],
					"text" : "s_TILTON $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-96",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1414.0, 648.0, 70.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"dialcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"fgdialcolor" : [ 0.768399306904929, 0.768399117237748, 0.7683991666346, 1.0 ],
					"fontsize" : 14.0,
					"id" : "obj-91",
					"maxclass" : "live.dial",
					"needlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1528.0, 562.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1549.0, 659.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"dialcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"fgdialcolor" : 						{
							"expression" : "themecolor.live_lcd_title"
						}
,
						"needlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 0.7071 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "Q",
							"parameter_mmax" : 16.0,
							"parameter_mmin" : 0.7071,
							"parameter_modmode" : 3,
							"parameter_shortname" : "Q",
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "Q"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-90",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1528.0, 662.0, 78.0, 22.0 ],
					"text" : "t_TONEQ $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1497.0, 481.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1497.0, 514.0, 97.0, 22.0 ],
					"text" : "u_TONEPOS $1"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"dialcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"fgdialcolor" : [ 0.768399306904929, 0.768399117237748, 0.7683991666346, 1.0 ],
					"fontsize" : 14.0,
					"id" : "obj-85",
					"maxclass" : "live.dial",
					"needlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1414.0, 553.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1527.0, 664.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"dialcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"fgdialcolor" : 						{
							"expression" : "themecolor.live_lcd_title"
						}
,
						"needlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 12000 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "TONE",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "TONE",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "TONE"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1414.0, 699.0, 102.0, 22.0 ],
					"text" : "r_TONEFREQ $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1394.0, 483.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1394.0, 514.0, 90.0, 22.0 ],
					"text" : "q_TONEON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-82",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1540.0, 314.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-75",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1538.0, 348.0, 118.0, 22.0 ],
					"text" : "p_SAFELIMITON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-72",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1452.0, 104.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-70",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1452.0, 139.0, 105.0, 22.0 ],
					"text" : "p_BANDSOLO $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 502.0, 98.0, 24.0, 24.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_enum" : [ "off", "on" ],
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "toggle",
							"parameter_mmax" : 1,
							"parameter_modmode" : 0,
							"parameter_shortname" : "toggle",
							"parameter_type" : 2
						}

					}
,
					"varname" : "toggle"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-67",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 502.0, 145.0, 84.0, 22.0 ],
					"text" : "p_DISTON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-66",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 731.0, 13.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 731.0, 51.0, 88.0, 22.0 ],
					"text" : "p_TILTPOS $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1436.0, 30.0, 31.0, 20.0 ],
					"text" : "high"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1401.0, 30.0, 28.0, 20.0 ],
					"text" : "mid"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1370.0, 30.0, 27.0, 20.0 ],
					"text" : "low"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 9,
							"minor" : 0,
							"revision" : 8,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 534.0, 117.0, 945.0, 851.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"fontsize" : 18.0,
									"id" : "obj-2",
									"linecount" : 40,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 9.0, 7.0, 897.0, 811.0 ],
									"text" : "// -----------------------------------------------------------------------------\n// PARÁMETROS\n// -----------------------------------------------------------------------------\nParam a_DRYWET(1, min=0, default=1, max=1);\nParam b_DRIVE(1, min=1, default=1, max=50);\nParam c_DC(0, min=0, default=0, max=1);         // DC offset - añade armónicos pares (asimetría)\nParam d_MODE(1, min=0, default=0, max=7);       // Continuo 0-7 (8 algoritmos)\nParam e_CEILING(0, min=-20, default=0, max=6);\nParam f_BYPASS(0, min=0, default=0, max=1);\nParam g_BITS(16, min=2, default=16, max=16);\nParam h_BITSON(0, min=0, default=0, max=1);\nParam i_TILT(0, min=-6, default=0, max=6);\n\n// Parámetros de filtros HPF/LPF\nParam j_HPF(250, min=20, default=250, max=1000);      // XOver low frequency (Hz)\nParam k_LPF(5000, min=1000, default=5000, max=20000); // XOver high frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable\n\n// Parámetros existentes\nParam k_INPUT(0, min=-12, default=0, max=12);   // Input trim gain\nParam l_OUTPUT(0, min=-24, default=0, max=12);  // Output makeup gain\nParam m_DOWNSAMPLE(0, min=0, default=0, max=99); // Factor de downsampling (0 = sin efecto)\nParam n_DOWNSAMPLEON(0, min=0, default=0, max=1); // Activar downsampling\n\nParam o_BAND(1, min=0, default=1, max=2); // 0=low,1=mid,2=high\n\nParam p_TILTPOS(0, min=0, default=0, max=1); // 0=Pre (Tilt→Dist), 1=Post (Dist→Tilt)\nParam p_DISTON(1, min=0, default=1, max=1); // 0=off, 1=on\n\nParam p_BANDSOLO(0, min=0, default=0, max=1); // 0=off, 1=solo banda seleccionada\nParam p_SAFELIMITON(0, min=0, default=0, max=1); // 0=off, 1=on\n\nParam q_TONEON(0,    min=0,    default=0,     max=1);        // 0=off, 1=on\nParam r_TONEFREQ(15000, min=20, default=15000, max=20000);  // Hz\n\n// Conmutador PRE/POST del LPF TONE: 0 = PRE (antes de la distorsión), 1 = POST (después, como ahora)\nParam s_TONEPOS(1, min=0, default=1, max=1);\n\n// Resonancia (Q) del LPF TONE (para ambos casos PRE/POST una vez ruteado)\nParam t_TONEQ(0.7071067811865476, min=0.7071067811865476, default=0.7071067811865476, max=16.0);"
								}

							}
 ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 49.0, 429.0, 81.0, 22.0 ],
					"text" : "p Parametros"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "preset", "int", "preset", "int", "" ],
					"patching_rect" : [ 208.0, 70.0, 100.0, 40.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-43", "attrui", "attr", "exportfolder", 4, "obj-43", "attrui", "Sequoia:/Users/jcb/JUCEProjects/JCBDistortion/exported-code/", 5, "obj-44", "number", "float", 0.25, 5, "obj-15", "toggle", "int", 1, 5, "obj-87", "number", "float", 3.0, 5, "obj-93", "number", "float", 0.0, 5, "obj-95", "number", "float", 0.5, 5, "obj-26", "number", "float", 0.0, 5, "obj-52", "toggle", "int", 0, 5, "obj-27", "toggle", "int", 0, 5, "obj-53", "number", "float", 16.0, 5, "obj-61", "number", "float", 0.0, 5, "obj-48", "number", "float", 0.0, 5, "obj-31", "number", "float", 0.0, 5, "obj-37", "number", "float", 0.0, 5, "obj-73", "multislider", "list", 0.0, 5, "obj-9", "toggle", "int", 0, 5, "obj-13", "number", "float", 0.0, 5, "obj-62", "toggle", "int", 1, 5, "obj-71", "number", "float", 256.358489990234375, 5, "obj-74", "number", "float", 5286.7919921875, 5, "obj-121", "live.dial", "float", 256.358489990234375, 5, "obj-122", "live.dial", "float", 5286.7919921875, 5, "obj-77", "toggle", "int", 0, 5, "obj-34", "number", "int", 1 ]
						}
, 						{
							"number" : 8,
							"data" : [ 5, "obj-43", "attrui", "attr", "exportfolder", 4, "obj-43", "attrui", "Sequoia:/Users/jcb/JUCEProjects/JCBDistortion/exported-code/", 5, "obj-44", "number", "float", 0.5, 5, "obj-15", "toggle", "int", 1, 5, "obj-87", "number", "float", 7.0, 5, "obj-93", "number", "float", 0.0, 5, "obj-95", "number", "float", 0.5, 5, "obj-26", "number", "float", 0.0, 5, "obj-52", "toggle", "int", 0, 5, "obj-27", "toggle", "int", 1, 5, "obj-53", "number", "float", 2.0, 5, "obj-61", "number", "float", 0.0, 5, "obj-48", "number", "float", 3.810126543045044, 5, "obj-31", "number", "float", 0.0, 5, "obj-37", "number", "float", -6.0, 5, "obj-73", "multislider", "list", 3.810126582278481, 5, "obj-9", "toggle", "int", 1, 5, "obj-13", "number", "float", 66.0, 5, "obj-62", "toggle", "int", 1, 5, "obj-71", "number", "float", 250.0, 5, "obj-74", "number", "float", 5791.9111328125, 5, "obj-121", "live.dial", "float", 250.0, 5, "obj-122", "live.dial", "float", 5791.9111328125, 5, "obj-77", "toggle", "int", 0, 5, "obj-34", "number", "float", 0.0, 5, "obj-66", "toggle", "int", 0, 5, "obj-68", "toggle", "int", 1, 5, "obj-72", "toggle", "int", 1, 5, "obj-82", "toggle", "int", 0, 5, "obj-76", "toggle", "int", 1, 5, "obj-85", "live.dial", "float", 60.816490173339844, 5, "obj-89", "toggle", "int", 1, 5, "obj-91", "live.dial", "float", 16.0 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1372.0, 56.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1435.0, 56.0, 29.5, 22.0 ],
					"text" : "2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1403.0, 56.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-34",
					"maxclass" : "flonum",
					"maximum" : 2.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1372.0, 101.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[4]",
							"parameter_mmax" : 2.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[4]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[4]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1372.0, 139.0, 72.0, 22.0 ],
					"text" : "o_BAND $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 237.0, 158.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 237.0, 189.0, 65.0, 22.0 ],
					"text" : "modout $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 302.0, 129.0, 21.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 208.0, 128.0, 88.0, 22.0 ],
					"text" : "open, loop 1, 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outlettype" : [ "signal", "signal", "bang" ],
					"patching_rect" : [ 209.0, 244.0, 121.0, 22.0 ],
					"text" : "sfplay~ 2"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"dialcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"fgdialcolor" : [ 0.768399306904929, 0.768399117237748, 0.7683991666346, 1.0 ],
					"fontsize" : 14.0,
					"id" : "obj-122",
					"maxclass" : "live.dial",
					"needlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1273.0, 475.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 717.0, 15.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"dialcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"fgdialcolor" : 						{
							"expression" : "themecolor.live_lcd_title"
						}
,
						"needlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 5000 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "LPF",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 1000.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "LPF",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "LPF"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"fontsize" : 14.0,
					"id" : "obj-121",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1029.0, 477.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 556.0, 15.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 250 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "HPF",
							"parameter_mmax" : 1000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "HPF",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "live.dial[11]"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-74",
					"maxclass" : "flonum",
					"maximum" : 20000.0,
					"minimum" : 1000.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1273.0, 573.0, 68.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 5000 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[2]",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 1000.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[2]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[2]"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-71",
					"maxclass" : "flonum",
					"maximum" : 1000.0,
					"minimum" : 20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1029.0, 573.0, 64.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 250 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[1]",
							"parameter_mmax" : 1000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[1]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1167.0, 840.0, 51.0, 22.0 ],
					"text" : "s parms"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1167.0, 439.0, 57.0, 57.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1167.0, 508.0, 51.0, 22.0 ],
					"text" : "l_SC $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1273.0, 606.0, 60.0, 22.0 ],
					"text" : "k_LPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1029.0, 606.0, 59.0, 22.0 ],
					"text" : "j_HPF $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-13",
					"maxclass" : "flonum",
					"maximum" : 99.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1225.0, 270.0, 103.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1224.0, 298.0, 129.0, 22.0 ],
					"text" : "m_DOWNSAMPLE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1055.0, 269.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1055.0, 298.0, 143.0, 22.0 ],
					"text" : "n_DOWNSAMPLEON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 143.0, 309.0, 49.0, 22.0 ],
					"text" : "r parms"
				}

			}
, 			{
				"box" : 				{
					"compatibility" : 1,
					"contdata" : 1,
					"id" : "obj-73",
					"maxclass" : "multislider",
					"numinlets" : 1,
					"numoutlets" : 2,
					"orientation" : 0,
					"outlettype" : [ "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1132.0, 139.0, 158.0, 35.0 ],
					"setminmax" : [ 0.0, 7.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 766.0, 467.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 637.0, 518.0, 82.0, 22.0 ],
					"text" : "adoutput~ 1 2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 626.0, 467.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1274.0, 38.0, 29.5, 22.0 ],
					"text" : "7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1243.0, 38.0, 29.5, 22.0 ],
					"text" : "6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1209.0, 38.0, 29.5, 22.0 ],
					"text" : "5"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-37",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -24.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1487.0, 188.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1487.0, 217.0, 84.0, 22.0 ],
					"text" : "l_OUTPUT $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-31",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 368.0, 156.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 368.0, 201.0, 74.0, 22.0 ],
					"text" : "k_INPUT $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1050.0, 38.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-48",
					"maxclass" : "flonum",
					"maximum" : 11.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1132.0, 184.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.33, 0.33, 0.33, 1.0 ],
					"id" : "obj-25",
					"margins" : [ 1.0, 0.0, 1.0, 0.0 ],
					"maxclass" : "plot~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"numpoints" : 441,
					"outlettype" : [ "" ],
					"patching_rect" : [ 637.0, 573.0, 276.0, 219.0 ],
					"prototypename" : "Audio Scope - Light",
					"subplots" : [ 						{
							"color" : [ 0.100000001490116, 0.899999976158142, 0.100000001490116, 1.0 ],
							"thickness" : 1.200000047683716,
							"point_style" : "none",
							"line_style" : "lines",
							"number_style" : "none",
							"filter" : "none",
							"domain_start" : 0.0,
							"domain_end" : 1.0,
							"domain_style" : "linear",
							"domain_markers" : [ 0.0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1.0 ],
							"domain_labels" : [  ],
							"range_start" : -1.0,
							"range_end" : 1.0,
							"range_style" : "linear",
							"range_markers" : [ -0.5, 0.0, 0.5 ],
							"range_labels" : [  ],
							"origin_x" : 0.0,
							"origin_y" : 0.0
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-61",
					"maxclass" : "flonum",
					"maximum" : 6.0,
					"minimum" : -6.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 746.0, 98.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 746.0, 145.0, 58.0, 22.0 ],
					"text" : "i_TILT $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-53",
					"maxclass" : "flonum",
					"maximum" : 16.0,
					"minimum" : 2.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 945.0, 171.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 16.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[5]",
							"parameter_mmax" : 16.0,
							"parameter_mmin" : 2.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[5]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[5]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 945.0, 218.0, 65.0, 22.0 ],
					"text" : "g_BITS $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1018.0, 171.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1018.0, 218.0, 83.0, 22.0 ],
					"text" : "h_BITSON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 396.0, 467.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 227.0, 467.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1176.0, 38.0, 29.5, 22.0 ],
					"text" : "4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1144.0, 38.0, 29.5, 22.0 ],
					"text" : "3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1113.0, 38.0, 29.5, 22.0 ],
					"text" : "2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1081.0, 38.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1511.0, 252.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1511.0, 282.0, 82.0, 22.0 ],
					"text" : "f_BYPASS $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-26",
					"maxclass" : "flonum",
					"maximum" : 6.0,
					"minimum" : -20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 829.0, 98.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 829.0, 145.0, 87.0, 22.0 ],
					"text" : "e_CEILING $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1132.0, 217.0, 75.0, 22.0 ],
					"text" : "d_MODE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"logfreq" : 1,
					"maxclass" : "spectroscope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 419.0, 675.0, 139.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 502.0, 576.0, 47.0, 22.0 ],
					"text" : "gate~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 502.0, 626.0, 40.0, 22.0 ],
					"text" : "*~ 0.1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 107.0, 62.0, 68.0, 22.0 ],
					"text" : "exportcode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 352.0, 119.0, 90.0, 22.0 ],
					"text" : "a_DRYWET $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-95",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 352.0, 73.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 1.0 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number[3]",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number[3]",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number[3]"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-93",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 678.0, 98.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-87",
					"maxclass" : "flonum",
					"maximum" : 50.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 593.0, 98.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 352.0, 488.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 180.0, 582.0, 47.0, 22.0 ],
					"text" : "gate~"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-44",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 352.0, 582.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.25 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 678.0, 145.0, 55.0, 22.0 ],
					"text" : "c_DC $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 593.0, 145.0, 75.0, 22.0 ],
					"text" : "b_DRIVE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 334.0, 683.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 180.0, 626.0, 40.0, 22.0 ],
					"text" : "*~ 0.1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"logfreq" : 1,
					"maxclass" : "spectroscope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 155.0, 675.0, 139.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 9,
							"minor" : 0,
							"revision" : 8,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 1954.0, 63.0, 882.0, 983.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 436.0, 846.0, 35.0, 22.0 ],
									"text" : "out 3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 839.0, 846.0, 35.0, 22.0 ],
									"text" : "out 5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 637.5, 846.0, 35.0, 22.0 ],
									"text" : "out 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 234.5, 846.0, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 33.0, 14.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 839.0, 14.0, 28.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"code" : "// VERSION TAG: step2-tone-prepost-switch (2025-08-24)\n// =============================================================================\n// MULTI-ALGORITHM DISTORTION WITH LR4 WORKING FILTERS\n// =============================================================================\n// Plugin de distorsión con múltiples algoritmos y morphing continuo\n// Filtros HPF/LPF simples que funcionan correctamente\n// Dry/Wet mezcla señal original (pre-trim) con señal completamente procesada\n// =============================================================================\n\n// -----------------------------------------------------------------------------\n// FUNCIONES DE DISTORSIÓN (asimetría por pendiente usando DC)\n// -----------------------------------------------------------------------------\n\r\n\n// MODO 0 - Soft Clipping - Saturación suave con función cúbica\nsoftclip(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lNorm = (inl >= 0 ? inl * lDrivePos : inl * lDriveNeg) / cell;\n    rNorm = (inr >= 0 ? inr * rDrivePos : inr * rDriveNeg) / cell;\n\n    lCubic = lNorm - (lNorm * lNorm * lNorm) / 3;\n    rCubic = rNorm - (rNorm * rNorm * rNorm) / 3;\n\n    lLimited = sign(lNorm) * (2.0 / 3.0);\n    rLimited = sign(rNorm) * (2.0 / 3.0);\n\n    lOut = (abs(lNorm) <= 1) ? lCubic : lLimited;\n    rOut = (abs(rNorm) <= 1) ? rCubic : rLimited;\n\n    return lOut * cell, rOut * cell;\n}\n\n// MODO 1 - Sigmoid\nsigmoid(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lAdj = inl >= 0 ? inl * lDrivePos : inl * lDriveNeg;\n    rAdj = inr >= 0 ? inr * rDrivePos : inr * rDriveNeg;\n\n    factor = -1;\n    l = (2 * (1 / (1 + exp(factor * lAdj)))) - 1;\n    r = (2 * (1 / (1 + exp(factor * rAdj)))) - 1;\n\n    lOut = clip(l * cell, -cell, cell);\n    rOut = clip(r * cell, -cell, cell);\n\n    return lOut, rOut;\n}\n\n// MODO 2 - Rectificador Full Wave\nrectF(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lAdj = inl >= 0 ? inl * lDrivePos : inl * lDriveNeg;\n    rAdj = inr >= 0 ? inr * rDrivePos : inr * rDriveNeg;\n\n    l = sign(lAdj) * abs(lAdj) * 0.707;\n    r = sign(rAdj) * abs(rAdj) * 0.707;\n\n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 3 - Fuzz Exponencial 1\nfuzzExp1(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lAdj = inl >= 0 ? inl * lDrivePos : inl * lDriveNeg;\n    rAdj = inr >= 0 ? inr * rDrivePos : inr * rDriveNeg;\n\n    signl = sign(lAdj);\n    signr = sign(rAdj);\n\n    l = signl * (1 - exp(-abs(lAdj)));\n    r = signr * (1 - exp(-abs(rAdj)));\n\n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 4 - Tangente Hiperbólica\ntangenteHiperbolica(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    l = inl >= 0 ? clip(inl * lDrivePos, -cell, cell)\n                 : clip(inl * lDriveNeg, -cell, cell);\n\n    r = inr >= 0 ? clip(inr * rDrivePos, -cell, cell)\n                 : clip(inr * rDriveNeg, -cell, cell);\n\n    lOut = tanh(l) / tanh(dr);\n    rOut = tanh(r) / tanh(dr);\n    return lOut, rOut;\n}\n\n// MODO 5 - Rectificador Half Wave\nrectH(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    rDrivePos = dr * (1.0 + (dc));\n\n    lPositive = max(inl * lDrivePos, 0);\n    rPositive = max(inr * rDrivePos, 0);\n\n    l = clip(lPositive * 0.5, -cell, cell);\n    r = clip(rPositive * 0.5, -cell, cell);\n    return l, r;\n}\n\n// MODO 6 - Arctangente\narctangent(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lAdj = inl >= 0 ? inl * lDrivePos : inl * lDriveNeg;\n    rAdj = inr >= 0 ? inr * rDrivePos : inr * rDriveNeg;\n\n    l = (2 / pi) * atan(lAdj * 2);\n    r = (2 / pi) * atan(rAdj * 2);\n\n    lOut = l * cell;\n    rOut = r * cell;\n    return lOut, rOut;\n}\n\n// MODO 7 - Hard Clip\nhardClip(inl, inr, dr, dc, cell) {\n    lDrivePos = dr * (1.0 + (dc));\n    lDriveNeg = dr * (1.0 - (dc));\n    rDrivePos = dr * (1.0 + (dc));\n    rDriveNeg = dr * (1.0 - (dc));\n\n    lDriven = inl >= 0 ? inl * lDrivePos : inl * lDriveNeg;\n    rDriven = inr >= 0 ? inr * rDrivePos : inr * rDriveNeg;\n\n    l = (lDriven > cell) ? cell : ((lDriven < -cell) ? -cell : lDriven);\n    r = (rDriven > cell) ? cell : ((rDriven < -cell) ? -cell : rDriven);\n\n    return l, r;\n}\n\n// Bit Crusher - Reduce la resolución de bits (modo clean)\nbitCrusher(inl, inr, bits) {\n    steps = pow(2, bits) - 1;\n    invSteps = 1 / steps;\n    l = round(inl * steps) * invSteps;\n    r = round(inr * steps) * invSteps;\n    return l, r;\n}\n\n// -----------------------------------------------------------------------------\n// PARÁMETROS\n// -----------------------------------------------------------------------------\nParam a_DRYWET(1, min=0, default=1, max=1);\nParam b_DRIVE(1, min=1, default=1, max=50);\nParam c_DC(0, min=0, default=0, max=1);         // DC offset - añade armónicos pares (asimetría)\nParam d_MODE(1, min=0, default=0, max=7);       // Continuo 0-7 (8 algoritmos)\nParam e_CEILING(0, min=-20, default=0, max=6);\nParam f_BYPASS(0, min=0, default=0, max=1);\nParam g_BITS(16, min=2, default=16, max=16);\nParam h_BITSON(0, min=0, default=0, max=1);\nParam i_TILT(0, min=-6, default=0, max=6);\nParam s_TILTON(1, min=0, default=1, max=1); // Activador de Tilt (0=off, 1=on)\n\n// Parámetros de filtros HPF/LPF\nParam j_HPF(250, min=20, default=250, max=1000);      // XOver low frequency (Hz)\nParam k_LPF(5000, min=1000, default=5000, max=20000); // XOver high frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable\n\n// Parámetros existentes\nParam k_INPUT(0, min=-12, default=0, max=12);   // Input trim gain\nParam l_OUTPUT(0, min=-24, default=0, max=12);  // Output makeup gain\nParam m_DOWNSAMPLE(0, min=0, default=0, max=99); // Factor de downsampling (0 = sin efecto)\nParam n_DOWNSAMPLEON(0, min=0, default=0, max=1); // Activar downsampling\n\nParam o_BAND(1, min=0, default=1, max=2); // 0=low,1=mid,2=high\n\nParam p_TILTPOS(0, min=0, default=0, max=1); // 0=Pre (Tilt→Dist), 1=Post (Dist→Tilt)\nParam p_DISTON(1, min=0, default=1, max=1); // 0=off, 1=on\n\nParam p_BANDSOLO(0, min=0, default=0, max=1); // 0=off, 1=solo banda seleccionada\nParam p_SAFELIMITON(0, min=0, default=0, max=1); // 0=off, 1=on\n\nParam q_TONEON(0,    min=0,    default=0,     max=1);        // 0=off, 1=on\nParam r_TONEFREQ(12000, min=20, default=20000, max=20000);  // Hz\n\n// NUEVO: Q del LPF TONE (2º orden RBJ)\nParam t_TONEQ(0.7071067811865476, min=0.7071067811865476, default=0.7071067811865476, max=16.0);\n\nParam u_TONEPOS(1, min=0, default=1, max=1); // 0=Pre (Tone→Dist), 1=Post (Dist→Tone)\n\n// -----------------------------------------------------------------------------\n// HISTORIALES PARA SMOOTHING\n\nHistory L_l1_x2(0), L_l1_y1(0), L_l1_y2(0), L_l2_x2(0);\nHistory L_l2_y1(0), L_l2_y2(0), L_h1_x2(0), L_h1_y1(0);\nHistory L_h1_y2(0), L_h2_x2(0), L_h2_y1(0), L_h2_y2(0);\nHistory L_m1_x2(0), L_m1_y1(0), L_m1_y2(0), L_m2_x2(0);\nHistory L_m2_y1(0), L_m2_y2(0), L_u1_x2(0), L_u1_y1(0);\nHistory L_u1_y2(0), L_u2_x2(0), L_u2_y1(0), L_u2_y2(0);\nHistory L_ap_low_lp1_x2(0), L_ap_low_lp1_y1(0), L_ap_low_lp1_y2(0), L_ap_low_lp2_x2(0);\nHistory L_ap_low_lp2_y1(0), L_ap_low_lp2_y2(0), L_ap_low_hp1_x2(0), L_ap_low_hp1_y1(0);\nHistory L_ap_low_hp1_y2(0), L_ap_low_hp2_x2(0), L_ap_low_hp2_y1(0), L_ap_low_hp2_y2(0);\nHistory L_ap1_lp1_x2(0), L_ap1_lp1_y1(0), L_ap1_lp1_y2(0), L_ap1_lp2_x2(0);\nHistory L_ap1_lp2_y1(0), L_ap1_lp2_y2(0), L_ap1_hp1_x2(0), L_ap1_hp1_y1(0);\nHistory L_ap1_hp1_y2(0), L_ap1_hp2_x2(0), L_ap1_hp2_y1(0), L_ap1_hp2_y2(0);\nHistory L_ap2_lp1_x2(0), L_ap2_lp1_y1(0), L_ap2_lp1_y2(0), L_ap2_lp2_x2(0);\nHistory L_ap2_lp2_y1(0), L_ap2_lp2_y2(0), L_ap2_hp1_x2(0), L_ap2_hp1_y1(0);\nHistory L_ap2_hp1_y2(0), L_ap2_hp2_x2(0), L_ap2_hp2_y1(0), L_ap2_hp2_y2(0);\nHistory R_l1_x2(0), R_l1_y1(0), R_l1_y2(0), R_l2_x2(0);\nHistory R_l2_y1(0), R_l2_y2(0), R_h1_x2(0), R_h1_y1(0);\nHistory R_h1_y2(0), R_h2_x2(0), R_h2_y1(0), R_h2_y2(0);\nHistory R_m1_x2(0), R_m1_y1(0), R_m1_y2(0), R_m2_x2(0);\nHistory R_m2_y1(0), R_m2_y2(0), R_u1_x2(0), R_u1_y1(0);\nHistory R_u1_y2(0), R_u2_x2(0), R_u2_y1(0), R_u2_y2(0);\nHistory R_ap_low_lp1_x2(0), R_ap_low_lp1_y1(0), R_ap_low_lp1_y2(0), R_ap_low_lp2_x2(0);\nHistory R_ap_low_lp2_y1(0), R_ap_low_lp2_y2(0), R_ap_low_hp1_x2(0), R_ap_low_hp1_y1(0);\nHistory R_ap_low_hp1_y2(0), R_ap_low_hp2_x2(0), R_ap_low_hp2_y1(0), R_ap_low_hp2_y2(0);\nHistory R_ap1_lp1_x2(0), R_ap1_lp1_y1(0), R_ap1_lp1_y2(0), R_ap1_lp2_x2(0);\nHistory R_ap1_lp2_y1(0), R_ap1_lp2_y2(0), R_ap1_hp1_x2(0), R_ap1_hp1_y1(0);\nHistory R_ap1_hp1_y2(0), R_ap1_hp2_x2(0), R_ap1_hp2_y1(0), R_ap1_hp2_y2(0);\nHistory R_ap2_lp1_x2(0), R_ap2_lp1_y1(0), R_ap2_lp1_y2(0), R_ap2_lp2_x2(0);\nHistory R_ap2_lp2_y1(0), R_ap2_lp2_y2(0), R_ap2_hp1_x2(0), R_ap2_hp1_y1(0);\nHistory R_ap2_hp1_y2(0), R_ap2_hp2_x2(0), R_ap2_hp2_y1(0), R_ap2_hp2_y2(0);\nHistory l1_x1(0), l1_x2(0), l1_y1(0), l1_y2(0);\nHistory l2_x1(0), l2_x2(0), l2_y1(0), l2_y2(0);\nHistory h1_x1(0), h1_x2(0), h1_y1(0), h1_y2(0);\nHistory h2_x1(0), h2_x2(0), h2_y1(0), h2_y2(0);\nHistory m1_x1(0), m1_x2(0), m1_y1(0), m1_y2(0);\nHistory m2_x1(0), m2_x2(0), m2_y1(0), m2_y2(0);\nHistory u1_x1(0), u1_x2(0), u1_y1(0), u1_y2(0);\nHistory u2_x1(0), u2_x2(0), u2_y1(0), u2_y2(0);\nHistory ap_low_lp1_x1(0), ap_low_lp1_x2(0), ap_low_lp1_y1(0), ap_low_lp1_y2(0);\nHistory ap_low_lp2_x1(0), ap_low_lp2_x2(0), ap_low_lp2_y1(0), ap_low_lp2_y2(0);\nHistory ap_low_hp1_x1(0), ap_low_hp1_x2(0), ap_low_hp1_y1(0), ap_low_hp1_y2(0);\nHistory ap_low_hp2_x1(0), ap_low_hp2_x2(0), ap_low_hp2_y1(0), ap_low_hp2_y2(0);\nHistory ap1_lp1_x1(0), ap1_lp1_x2(0), ap1_lp1_y1(0), ap1_lp1_y2(0);\nHistory ap1_lp2_x1(0), ap1_lp2_x2(0), ap1_lp2_y1(0), ap1_lp2_y2(0);\nHistory ap1_hp1_x1(0), ap1_hp1_x2(0), ap1_hp1_y1(0), ap1_hp1_y2(0);\nHistory ap1_hp2_x1(0), ap1_hp2_x2(0), ap1_hp2_y1(0), ap1_hp2_y2(0);\nHistory ap2_lp1_x1(0), ap2_lp1_x2(0), ap2_lp1_y1(0), ap2_lp1_y2(0);\nHistory ap2_lp2_x1(0), ap2_lp2_x2(0), ap2_lp2_y1(0), ap2_lp2_y2(0);\nHistory ap2_hp1_x1(0), ap2_hp1_x2(0), ap2_hp1_y1(0), ap2_hp1_y2(0);\nHistory ap2_hp2_x1(0), ap2_hp2_x2(0), ap2_hp2_y1(0), ap2_hp2_y2(0);\nHistory hBand(1);\n// -----------------------------------------------------------------------------\n// Para suavizar cambios de modo\n// Para suavizar factor de downsampling\n// Para suavizar activación de downsampling\n// Para suavizar bypass y evitar clicks\n\n// Historiales para filtros de 1 polo (más simples)\n// Historiales para smoothing de filtros\n// Historiales para el downsampler con phasor\n// Historiales para filtros Tilt\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO PRINCIPAL\n// -----------------------------------------------------------------------------\nHistory hDrive(0);\nHistory hDc(0);\nHistory hDrywet(0);\nHistory hBits(0);\nHistory hBitson(0);\nHistory hTilt(0);\nHistory hTiltOn(1);\nHistory hInput(0);\nHistory hOutput(0);\nHistory hMode(0);\n\nHistory hDownsample(0);\nHistory hDownsampleOn(0);\nHistory hBypass(0);\nHistory hpfL_z1(0);\nHistory hpfR_z1(0);\nHistory lpfL_z1(0);\nHistory lpfR_z1(0);\nHistory hpfFreqHistory(0);\nHistory lpfFreqHistory(0);\nHistory scEnableHistory(0);\nHistory dsPhasor(0);\n\nHistory dsPhase(0);\nHistory dsTrigPrev(0);\nHistory dsEnablePrev(0);\n\n//History tiltL1(0), tiltL2(0), tiltL3(0), tiltL4(0);\n//History tiltR1(0), tiltR2(0), tiltR3(0), tiltR4(0);\nHistory tiltLsL1(0), tiltLsL2(0), tiltLsL3(0), tiltLsL4(0);\nHistory tiltLsR1(0), tiltLsR2(0), tiltLsR3(0), tiltLsR4(0);\nHistory tiltHsL1(0), tiltHsL2(0), tiltHsL3(0), tiltHsL4(0);\nHistory tiltHsR1(0), tiltHsR2(0), tiltHsR3(0), tiltHsR4(0);\n\nHistory hTiltPos(0);\nHistory hTonePos(1);\n\nHistory postTiltLsL1(0), postTiltLsL2(0), postTiltLsL3(0), postTiltLsL4(0);\nHistory postTiltLsR1(0), postTiltLsR2(0), postTiltLsR3(0), postTiltLsR4(0);\nHistory postTiltHsL1(0), postTiltHsL2(0), postTiltHsL3(0), postTiltHsL4(0);\nHistory postTiltHsR1(0), postTiltHsR2(0), postTiltHsR3(0), postTiltHsR4(0);\n\nHistory L_l1_x1(0);\nHistory R_l1_x1(0);\nHistory L_l2_x1(0);\nHistory R_l2_x1(0);\nHistory L_h1_x1(0);\nHistory R_h1_x1(0);\nHistory L_h2_x1(0);\nHistory R_h2_x1(0);\nHistory L_m1_x1(0);\nHistory R_m1_x1(0);\nHistory L_m2_x1(0);\nHistory R_m2_x1(0);\nHistory L_u1_x1(0);\nHistory R_u1_x1(0);\nHistory L_u2_x1(0);\nHistory R_u2_x1(0);\nHistory L_ap_low_lp1_x1(0);\nHistory R_ap_low_lp1_x1(0);\nHistory L_ap_low_lp2_x1(0);\nHistory R_ap_low_lp2_x1(0);\nHistory L_ap_low_hp1_x1(0);\nHistory R_ap_low_hp1_x1(0);\nHistory L_ap_low_hp2_x1(0);\nHistory R_ap_low_hp2_x1(0);\nHistory L_ap1_lp1_x1(0);\nHistory R_ap1_lp1_x1(0);\nHistory L_ap1_lp2_x1(0);\nHistory R_ap1_lp2_x1(0);\nHistory L_ap1_hp1_x1(0);\nHistory R_ap1_hp1_x1(0);\nHistory L_ap1_hp2_x1(0);\nHistory R_ap1_hp2_x1(0);\nHistory L_ap2_lp1_x1(0);\nHistory R_ap2_lp1_x1(0);\nHistory L_ap2_lp2_x1(0);\nHistory R_ap2_lp2_x1(0);\nHistory L_ap2_hp1_x1(0);\nHistory R_ap2_hp1_x1(0);\nHistory L_ap2_hp2_x1(0);\nHistory R_ap2_hp2_x1(0);\n\nHistory hDistOn(1);\n\nHistory hBandSolo(0);\n\nHistory hSafeLimitOn(0);\n\n// Smoothing y estados del LPF global post Dry/Wet\nHistory hToneOn(0), hToneFreq(12000);\nHistory toneL_x1(0), toneL_x2(0), toneL_y1(0), toneL_y2(0);\nHistory toneR_x1(0), toneR_x2(0), toneR_y1(0), toneR_y2(0);\n// NUEVO: smoothing del Q del TONE\nHistory hToneQ(0.7071067811865476);\n// PRE-mode LPF states (antes de la distorsión) para TONE+Q\nHistory preToneAL_x1(0), preToneAL_x2(0), preToneAL_y1(0), preToneAL_y2(0);\nHistory preToneAR_x1(0), preToneAR_x2(0), preToneAR_y1(0), preToneAR_y2(0);\nHistory preToneBL_x1(0), preToneBL_x2(0), preToneBL_y1(0), preToneBL_y2(0);\nHistory preToneBR_x1(0), preToneBR_x2(0), preToneBR_y1(0), preToneBR_y2(0);\n\n// Allpass (dry) para compensar el LPF del wet\nHistory toneApL_x1(0), toneApL_x2(0), toneApL_y1(0), toneApL_y2(0);\nHistory toneApR_x1(0), toneApR_x2(0), toneApR_y1(0), toneApR_y2(0);\n\n// Entrada\nlIn = in1;\nrIn = in2;\n\n// Smoothing de parámetros\nsmoothFactor = 0.999;\nhDrive = hDrive * smoothFactor + b_DRIVE * (1 - smoothFactor);\ndrive = hDrive;\nhDc = hDc * smoothFactor + c_DC * (1 - smoothFactor);\ndc = hDc;\nhDrywet = hDrywet * smoothFactor + a_DRYWET * (1 - smoothFactor);\ndrywet = hDrywet;\nhBits = hBits * smoothFactor + g_BITS * (1 - smoothFactor);\nbits = hBits;\nhBitson = hBitson * smoothFactor + h_BITSON * (1 - smoothFactor);\nbitson = hBitson;\nhTilt = hTilt * smoothFactor + i_TILT * (1 - smoothFactor);\ntiltDb = hTilt;\n// Smoothing independiente para el activador de Tilt y toggles\ntoggleSmooth = 0.99; // ~1% por muestra (~20-30 ms @48k) para toggles (declick)\nonSmoothTilt = toggleSmooth; // usado solo para Tilt ON/OFF\nhTiltOn   = hTiltOn * onSmoothTilt + s_TILTON * (1 - onSmoothTilt);\ntiltOn    = clamp(hTiltOn, 0, 1);\nhInput = hInput * smoothFactor + k_INPUT * (1 - smoothFactor);\ninputTrimDb = hInput;\nhOutput = hOutput * smoothFactor + l_OUTPUT * (1 - smoothFactor);\noutputMakeupDb = hOutput;\n\nhBand = hBand * smoothFactor + o_BAND * (1 - smoothFactor);\nsmoothedBand = hBand;\n\n// Suavizado especial para MODE con factor más agresivo para evitar clicks\nmodeSmoothFactor = 0.99;  // Más rápido que otros parámetros pero aún suave\nhMode = hMode * modeSmoothFactor + d_MODE * (1 - modeSmoothFactor);\nsmoothedMode = hMode;\n\n// Suavizado del downsampling\nhDownsample = hDownsample * smoothFactor + m_DOWNSAMPLE * (1 - smoothFactor);\nonSmooth = 0.9; // respuesta rápida (~10% por muestra)\nhDownsampleOn = hDownsampleOn * onSmooth + n_DOWNSAMPLEON * (1 - onSmooth);\ndownsampleOn = hDownsampleOn;\ntoneSmooth = 0.99; // suavizado específico para activadores tipo TONE ON/OFF\n\n// Suavizado del bypass\nhBypass = hBypass * smoothFactor + (1 - f_BYPASS) * (1 - smoothFactor);\nbypass = hBypass;\n\n// Suavizado de parámetros de filtros\nsmoothHpfFreq = (hpfFreqHistory * smoothFactor) + (j_HPF * (1 - smoothFactor));\nhpfFreqHistory = fixdenorm(smoothHpfFreq);\n\nsmoothLpfFreq = (lpfFreqHistory * smoothFactor) + (k_LPF * (1 - smoothFactor));\nlpfFreqHistory = fixdenorm(smoothLpfFreq);\n\nsmoothScEnable = (scEnableHistory * smoothFactor) + (l_SC * (1 - smoothFactor));\nscEnableHistory = fixdenorm(smoothScEnable);\n\nhTiltPos = hTiltPos * smoothFactor + p_TILTPOS * (1 - smoothFactor);\nwPost    = clamp(hTiltPos, 0, 1);     // peso de la ruta Post\nwPre     = 1 - wPost;                  // peso de la ruta Pre\n\nhDistOn = hDistOn * smoothFactor + p_DISTON * (1 - smoothFactor);\nwDist   = clamp(hDistOn, 0, 1); // peso Dist ON\nwClean  = 1 - wDist;             // peso Bypass Dist\n\nhBandSolo = hBandSolo * smoothFactor + p_BANDSOLO * (1 - smoothFactor);\nwBandSolo = clamp(hBandSolo, 0, 1);\n\nhSafeLimitOn = hSafeLimitOn * smoothFactor + p_SAFELIMITON * (1 - smoothFactor);\nsafeOn = clamp(hSafeLimitOn, 0, 1);\n\n// Smoothing LPF global (toggle y frecuencia)\nhToneOn   = hToneOn   * toneSmooth   + q_TONEON   * (1 - toneSmooth);\ntoneOn    = clamp(hToneOn, 0, 1);\n\nhToneFreq = hToneFreq * smoothFactor + r_TONEFREQ * (1 - smoothFactor);\ntoneFreq  = hToneFreq;\n\n// NUEVO: smoothing del Q y clamp de estabilidad\nhToneQ    = hToneQ    * smoothFactor + t_TONEQ    * (1 - smoothFactor);\ntq        = clamp(hToneQ, 0.125, 16.0);\n// TONE+Q PRE/POST selector smoothing\nhTonePos = hTonePos * smoothFactor + u_TONEPOS * (1 - smoothFactor);\nwTonePost = clamp(hTonePos, 0, 1); // 1 = POST (comportamiento actual)\nwTonePre  = 1 - wTonePost;\n\n// ---------- COEFICIENTES TONE+Q (LPF RBJ + Allpass DRY) ----------\n// (Se calculan aquí para que estén definidos tanto para PRE como para POST)\n\n// ---------- LPF TONE+Q (RBJ) ----------\nomegaT  = (toneFreq * twopi) / samplerate;\nsinT    = sin(omegaT);\ncosT    = cos(omegaT);\n// Usar Q ajustable (tq) en lugar de Butterworth fijo\nalphaT  = sinT / (2 * tq);\n\n// Coeficientes LPF 2º orden (RBJ), normalizados a a0\nb0T = (1 - cosT) * 0.5;\nb1T = 1 - cosT;\nb2T = (1 - cosT) * 0.5;\na0T = 1 + alphaT;\na1T = -2 * cosT;\na2T = 1 - alphaT;\n\ninv_a0T = 1 / a0T;\nt_a0 = b0T * inv_a0T;\nt_a1 = b1T * inv_a0T;\nt_a2 = b2T * inv_a0T;\nt_b1 = a1T * inv_a0T;\nt_b2 = a2T * inv_a0T;\n\n// ---------- Allpass equivalente para la ruta DRY ----------\n// H_ap(z) = (a2 + a1 z^-1 + 1 z^-2) / (1 + a1 z^-1 + a2 z^-2)\n// En nuestra notación normalizada, los feedback del LPF son t_b1 y t_b2\nap_b0 = t_b2;\nap_b1 = t_b1;\nap_b2 = 1;\nap_a1 = t_b1;\nap_a2 = t_b2;\n\n// -----------------------------------------------------------------------------\n// -----------------------------------------------------------------------------\n// CONVERSIONES A LINEAL PARA TRIMS Y CEILING\n// -----------------------------------------------------------------------------\nceiling = dbtoa(e_CEILING);\ninputTrimLinear = dbtoa(inputTrimDb);\noutputMakeupLinear = dbtoa(outputMakeupDb);\n\n// -----------------------------------------------------------------------------\n// INPUT TRIM (define lTrimmed/rTrimmed antes del crossover)\n// -----------------------------------------------------------------------------\nlTrimmed = lIn * inputTrimLinear;\nrTrimmed = rIn * inputTrimLinear;\n// REEMPLAZO: Crossover LR4 estéreo con selector de banda + Dry allpass compensado\n// -----------------------------------------------------------------------------\nscSm = smoothScEnable; // enable suavizado del crossover\n\n// === L_bindings ===\nL_loF = smoothHpfFreq;\nL_hiF = smoothLpfFreq;\n// L_Crossover L_LR4 L_de 3 L_bandas L_con compensación L_de L_fase L_correcta\n// out1: L_Low (20-250Hz)\n// out2: L_Mid (250-5kHz)\n// out3: L_High (5k-20kHz)\n// out4: L_Suma L_de L_las 3 L_bandas (L_debe L_hacer L_null L_test L_con L_entrada)\n\n// ===== L_DECLARACIONES =====\n// L_Estados L_para L_los 8 L_biquads L_del L_crossover L_principal\n// L_Low L_stage 1\n// L_Low L_stage 2\n// L_Rest L_HP L_stage 1\n// L_Rest L_HP L_stage 2\n// L_Mid L_LP L_stage 1\n// L_Mid L_LP L_stage 2\n// L_High L_HP L_stage 1\n// L_High L_HP L_stage 2\n\n// L_Estados L_para L_all-L_pass L_de compensación L_en L_la L_banda L_LOW\n// ===== L_PROCESO =====\nL_x = lTrimmed;\n\n// L_Proteger L_frecuencias\nL_sr = samplerate;\nL_loF = max(10, min(L_loF, 0.45 * L_sr));\nL_hiFr = max(10, min(L_hiF, 0.45 * L_sr));\nL_hiF = max(L_hiFr, L_loF + 1);\n\n// L_Constantes\nL_QBW = 0.7071067811865476; // sqrt(2)/2 L_para L_Butterworth\n\n// === L_Coeficientes L_Butterworth @ L_loF ===\nL_w0_lo = TWOPI * L_loF / L_sr;\nL_cos_lo = cos(L_w0_lo);\nL_sin_lo = sin(L_w0_lo);\nL_alpha_lo = L_sin_lo / (2 * L_QBW);\nL_a0_lo = 1 + L_alpha_lo;\nL_a1_lo = -2 * L_cos_lo;\nL_a2_lo = 1 - L_alpha_lo;\n\n// L_LP @ L_loF (L_normalizado)\nL_lp_b0_l = ((1 - L_cos_lo) * 0.5) / L_a0_lo;\nL_lp_b1_l = (1 - L_cos_lo) / L_a0_lo;\nL_lp_b2_l = L_lp_b0_l;\nL_lp_a1_l = L_a1_lo / L_a0_lo;\nL_lp_a2_l = L_a2_lo / L_a0_lo;\n\n// L_HP @ L_loF (L_normalizado)\nL_hp_b0_l = ((1 + L_cos_lo) * 0.5) / L_a0_lo;\nL_hp_b1_l = -(1 + L_cos_lo) / L_a0_lo;\nL_hp_b2_l = L_hp_b0_l;\nL_hp_a1_l = L_lp_a1_l;\nL_hp_a2_l = L_lp_a2_l;\n\n// === L_Coeficientes L_Butterworth @ L_hiF ===\nL_w0_hi = TWOPI * L_hiF / L_sr;\nL_cos_hi = cos(L_w0_hi);\nL_sin_hi = sin(L_w0_hi);\nL_alpha_hi = L_sin_hi / (2 * L_QBW);\nL_a0_hi = 1 + L_alpha_hi;\nL_a1_hi = -2 * L_cos_hi;\nL_a2_hi = 1 - L_alpha_hi;\n\n// L_LP @ L_hiF (L_normalizado)\nL_lp_b0_h = ((1 - L_cos_hi) * 0.5) / L_a0_hi;\nL_lp_b1_h = (1 - L_cos_hi) / L_a0_hi;\nL_lp_b2_h = L_lp_b0_h;\nL_lp_a1_h = L_a1_hi / L_a0_hi;\nL_lp_a2_h = L_a2_hi / L_a0_hi;\n\n// L_HP @ L_hiF (L_normalizado)\nL_hp_b0_h = ((1 + L_cos_hi) * 0.5) / L_a0_hi;\nL_hp_b1_h = -(1 + L_cos_hi) / L_a0_hi;\nL_hp_b2_h = L_hp_b0_h;\nL_hp_a1_h = L_lp_a1_h;\nL_hp_a2_h = L_lp_a2_h;\n\n// ===== L_PRIMER L_CORTE @ L_loF: L_low (L_LP) L_y L_rest (L_HP) =====\n\n// L_LP L_Stage 1 L_para L_LOW\nL_l1_x1p = fixdenorm(L_l1_x1);\nL_l1_x2p = fixdenorm(L_l1_x2);\nL_l1_y1p = fixdenorm(L_l1_y1);\nL_l1_y2p = fixdenorm(L_l1_y2);\nL_low_s1 = L_lp_b0_l*L_x + L_lp_b1_l*L_l1_x1p + L_lp_b2_l*L_l1_x2p - L_lp_a1_l*L_l1_y1p - L_lp_a2_l*L_l1_y2p;\nL_l1_x2 = L_l1_x1p; L_l1_x1 = L_x; L_l1_y2 = L_l1_y1p; L_l1_y1 = L_low_s1;\n\n// L_LP L_Stage 2 L_para L_LOW\nL_l2_x1p = fixdenorm(L_l2_x1);\nL_l2_x2p = fixdenorm(L_l2_x2);\nL_l2_y1p = fixdenorm(L_l2_y1);\nL_l2_y2p = fixdenorm(L_l2_y2);\nL_low_raw = L_lp_b0_l*L_low_s1 + L_lp_b1_l*L_l2_x1p + L_lp_b2_l*L_l2_x2p - L_lp_a1_l*L_l2_y1p - L_lp_a2_l*L_l2_y2p;\nL_l2_x2 = L_l2_x1p; L_l2_x1 = L_low_s1; L_l2_y2 = L_l2_y1p; L_l2_y1 = L_low_raw;\n\n// L_HP L_Stage 1 L_para L_REST\nL_h1_x1p = fixdenorm(L_h1_x1);\nL_h1_x2p = fixdenorm(L_h1_x2);\nL_h1_y1p = fixdenorm(L_h1_y1);\nL_h1_y2p = fixdenorm(L_h1_y2);\nL_rest_s1 = L_hp_b0_l*L_x + L_hp_b1_l*L_h1_x1p + L_hp_b2_l*L_h1_x2p - L_hp_a1_l*L_h1_y1p - L_hp_a2_l*L_h1_y2p;\nL_h1_x2 = L_h1_x1p; L_h1_x1 = L_x; L_h1_y2 = L_h1_y1p; L_h1_y1 = L_rest_s1;\n\n// L_HP L_Stage 2 L_para L_REST\nL_h2_x1p = fixdenorm(L_h2_x1);\nL_h2_x2p = fixdenorm(L_h2_x2);\nL_h2_y1p = fixdenorm(L_h2_y1);\nL_h2_y2p = fixdenorm(L_h2_y2);\nL_rest = L_hp_b0_l*L_rest_s1 + L_hp_b1_l*L_h2_x1p + L_hp_b2_l*L_h2_x2p - L_hp_a1_l*L_h2_y1p - L_hp_a2_l*L_h2_y2p;\nL_h2_x2 = L_h2_x1p; L_h2_x1 = L_rest_s1; L_h2_y2 = L_h2_y1p; L_h2_y1 = L_rest;\n\n// ===== COMPENSACIÓN L_ALL-L_PASS L_para L_LOW =====\n// L_Aplicamos L_un L_all-L_pass L_LP+L_HP @ L_hiF L_a L_la señal L_LOW L_para L_igualar L_el L_delay\n\n// L_All-L_pass L_LP L_stage 1 L_sobre L_low_raw\nL_ap_low_lp1_x1p = fixdenorm(L_ap_low_lp1_x1);\nL_ap_low_lp1_x2p = fixdenorm(L_ap_low_lp1_x2);\nL_ap_low_lp1_y1p = fixdenorm(L_ap_low_lp1_y1);\nL_ap_low_lp1_y2p = fixdenorm(L_ap_low_lp1_y2);\nL_ap_low_lp_s1 = L_lp_b0_h*L_low_raw + L_lp_b1_h*L_ap_low_lp1_x1p + L_lp_b2_h*L_ap_low_lp1_x2p\n               - L_lp_a1_h*L_ap_low_lp1_y1p - L_lp_a2_h*L_ap_low_lp1_y2p;\nL_ap_low_lp1_x2 = L_ap_low_lp1_x1p; L_ap_low_lp1_x1 = L_low_raw;\nL_ap_low_lp1_y2 = L_ap_low_lp1_y1p; L_ap_low_lp1_y1 = L_ap_low_lp_s1;\n\n// L_All-L_pass L_LP L_stage 2\nL_ap_low_lp2_x1p = fixdenorm(L_ap_low_lp2_x1);\nL_ap_low_lp2_x2p = fixdenorm(L_ap_low_lp2_x2);\nL_ap_low_lp2_y1p = fixdenorm(L_ap_low_lp2_y1);\nL_ap_low_lp2_y2p = fixdenorm(L_ap_low_lp2_y2);\nL_ap_low_lp = L_lp_b0_h*L_ap_low_lp_s1 + L_lp_b1_h*L_ap_low_lp2_x1p + L_lp_b2_h*L_ap_low_lp2_x2p\n            - L_lp_a1_h*L_ap_low_lp2_y1p - L_lp_a2_h*L_ap_low_lp2_y2p;\nL_ap_low_lp2_x2 = L_ap_low_lp2_x1p; L_ap_low_lp2_x1 = L_ap_low_lp_s1;\nL_ap_low_lp2_y2 = L_ap_low_lp2_y1p; L_ap_low_lp2_y1 = L_ap_low_lp;\n\n// L_All-L_pass L_HP L_stage 1 L_sobre L_low_raw\nL_ap_low_hp1_x1p = fixdenorm(L_ap_low_hp1_x1);\nL_ap_low_hp1_x2p = fixdenorm(L_ap_low_hp1_x2);\nL_ap_low_hp1_y1p = fixdenorm(L_ap_low_hp1_y1);\nL_ap_low_hp1_y2p = fixdenorm(L_ap_low_hp1_y2);\nL_ap_low_hp_s1 = L_hp_b0_h*L_low_raw + L_hp_b1_h*L_ap_low_hp1_x1p + L_hp_b2_h*L_ap_low_hp1_x2p\n               - L_hp_a1_h*L_ap_low_hp1_y1p - L_hp_a2_h*L_ap_low_hp1_y2p;\nL_ap_low_hp1_x2 = L_ap_low_hp1_x1p; L_ap_low_hp1_x1 = L_low_raw;\nL_ap_low_hp1_y2 = L_ap_low_hp1_y1p; L_ap_low_hp1_y1 = L_ap_low_hp_s1;\n\n// L_All-L_pass L_HP L_stage 2\nL_ap_low_hp2_x1p = fixdenorm(L_ap_low_hp2_x1);\nL_ap_low_hp2_x2p = fixdenorm(L_ap_low_hp2_x2);\nL_ap_low_hp2_y1p = fixdenorm(L_ap_low_hp2_y1);\nL_ap_low_hp2_y2p = fixdenorm(L_ap_low_hp2_y2);\nL_ap_low_hp = L_hp_b0_h*L_ap_low_hp_s1 + L_hp_b1_h*L_ap_low_hp2_x1p + L_hp_b2_h*L_ap_low_hp2_x2p\n            - L_hp_a1_h*L_ap_low_hp2_y1p - L_hp_a2_h*L_ap_low_hp2_y2p;\nL_ap_low_hp2_x2 = L_ap_low_hp2_x1p; L_ap_low_hp2_x1 = L_ap_low_hp_s1;\nL_ap_low_hp2_y2 = L_ap_low_hp2_y1p; L_ap_low_hp2_y1 = L_ap_low_hp;\n\n// L_LOW L_compensado (L_all-L_pass L_reconstruye L_la señal L_con L_el L_mismo L_delay L_que L_mid/L_high)\nL_low = L_ap_low_lp + L_ap_low_hp;\n\n// ===== L_SEGUNDO L_CORTE @ L_hiF L_sobre L_REST: L_mid (L_LP) L_y L_high (L_HP) =====\n\n// L_LP L_Stage 1 L_para L_MID\nL_m1_x1p = fixdenorm(L_m1_x1);\nL_m1_x2p = fixdenorm(L_m1_x2);\nL_m1_y1p = fixdenorm(L_m1_y1);\nL_m1_y2p = fixdenorm(L_m1_y2);\nL_mid_s1 = L_lp_b0_h*L_rest + L_lp_b1_h*L_m1_x1p + L_lp_b2_h*L_m1_x2p - L_lp_a1_h*L_m1_y1p - L_lp_a2_h*L_m1_y2p;\nL_m1_x2 = L_m1_x1p; L_m1_x1 = L_rest; L_m1_y2 = L_m1_y1p; L_m1_y1 = L_mid_s1;\n\n// L_LP L_Stage 2 L_para L_MID\nL_m2_x1p = fixdenorm(L_m2_x1);\nL_m2_x2p = fixdenorm(L_m2_x2);\nL_m2_y1p = fixdenorm(L_m2_y1);\nL_m2_y2p = fixdenorm(L_m2_y2);\nL_mid = L_lp_b0_h*L_mid_s1 + L_lp_b1_h*L_m2_x1p + L_lp_b2_h*L_m2_x2p - L_lp_a1_h*L_m2_y1p - L_lp_a2_h*L_m2_y2p;\nL_m2_x2 = L_m2_x1p; L_m2_x1 = L_mid_s1; L_m2_y2 = L_m2_y1p; L_m2_y1 = L_mid;\n\n// L_HP L_Stage 1 L_para L_HIGH\nL_u1_x1p = fixdenorm(L_u1_x1);\nL_u1_x2p = fixdenorm(L_u1_x2);\nL_u1_y1p = fixdenorm(L_u1_y1);\nL_u1_y2p = fixdenorm(L_u1_y2);\nL_high_s1 = L_hp_b0_h*L_rest + L_hp_b1_h*L_u1_x1p + L_hp_b2_h*L_u1_x2p - L_hp_a1_h*L_u1_y1p - L_hp_a2_h*L_u1_y2p;\nL_u1_x2 = L_u1_x1p; L_u1_x1 = L_rest; L_u1_y2 = L_u1_y1p; L_u1_y1 = L_high_s1;\n\n// L_HP L_Stage 2 L_para L_HIGH\nL_u2_x1p = fixdenorm(L_u2_x1);\nL_u2_x2p = fixdenorm(L_u2_x2);\nL_u2_y1p = fixdenorm(L_u2_y1);\nL_u2_y2p = fixdenorm(L_u2_y2);\nL_high = L_hp_b0_h*L_high_s1 + L_hp_b1_h*L_u2_x1p + L_hp_b2_h*L_u2_x2p - L_hp_a1_h*L_u2_y1p - L_hp_a2_h*L_u2_y2p;\nL_u2_x2 = L_u2_x1p; L_u2_x1 = L_high_s1; L_u2_y2 = L_u2_y1p; L_u2_y1 = L_high;\n\n// ===== L_SALIDAS =====\nlowL = L_low;   // L_Graves L_compensados\nmidL = L_mid;   // L_Medios\nhighL = L_high;  // L_Agudos\n\n// === R_bindings ===\nR_loF = smoothHpfFreq;\nR_hiF = smoothLpfFreq;\n// R_Crossover R_LR4 R_de 3 R_bandas R_con compensación R_de R_fase R_correcta\n// out1: R_Low (20-250Hz)\n// out2: R_Mid (250-5kHz)\n// out3: R_High (5k-20kHz)\n// out4: R_Suma R_de R_las 3 R_bandas (R_debe R_hacer R_null R_test R_con R_entrada)\n\n// ===== R_DECLARACIONES =====\n// R_Estados R_para R_los 8 R_biquads R_del R_crossover R_principal\n// R_Low R_stage 1\n// R_Low R_stage 2\n// R_Rest R_HP R_stage 1\n// R_Rest R_HP R_stage 2\n// R_Mid R_LP R_stage 1\n// R_Mid R_LP R_stage 2\n// R_High R_HP R_stage 1\n// R_High R_HP R_stage 2\n\n// R_Estados R_para R_all-R_pass R_de compensación R_en R_la R_banda R_LOW\n// ===== R_PROCESO =====\nR_x = rTrimmed;\n\n// R_Proteger R_frecuencias\nR_sr = samplerate;\nR_loF = max(10, min(R_loF, 0.45 * R_sr));\nR_hiFr = max(10, min(R_hiF, 0.45 * R_sr));\nR_hiF = max(R_hiFr, R_loF + 1);\n\n// R_Constantes\nR_QBW = 0.7071067811865476; // sqrt(2)/2 R_para R_Butterworth\n\n// === R_Coeficientes R_Butterworth @ R_loF ===\nR_w0_lo = TWOPI * R_loF / R_sr;\nR_cos_lo = cos(R_w0_lo);\nR_sin_lo = sin(R_w0_lo);\nR_alpha_lo = R_sin_lo / (2 * R_QBW);\nR_a0_lo = 1 + R_alpha_lo;\nR_a1_lo = -2 * R_cos_lo;\nR_a2_lo = 1 - R_alpha_lo;\n\n// R_LP @ R_loF (R_normalizado)\nR_lp_b0_l = ((1 - R_cos_lo) * 0.5) / R_a0_lo;\nR_lp_b1_l = (1 - R_cos_lo) / R_a0_lo;\nR_lp_b2_l = R_lp_b0_l;\nR_lp_a1_l = R_a1_lo / R_a0_lo;\nR_lp_a2_l = R_a2_lo / R_a0_lo;\n\n// R_HP @ R_loF (R_normalizado)\nR_hp_b0_l = ((1 + R_cos_lo) * 0.5) / R_a0_lo;\nR_hp_b1_l = -(1 + R_cos_lo) / R_a0_lo;\nR_hp_b2_l = R_hp_b0_l;\nR_hp_a1_l = R_lp_a1_l;\nR_hp_a2_l = R_lp_a2_l;\n\n// === R_Coeficientes R_Butterworth @ R_hiF ===\nR_w0_hi = TWOPI * R_hiF / R_sr;\nR_cos_hi = cos(R_w0_hi);\nR_sin_hi = sin(R_w0_hi);\nR_alpha_hi = R_sin_hi / (2 * R_QBW);\nR_a0_hi = 1 + R_alpha_hi;\nR_a1_hi = -2 * R_cos_hi;\nR_a2_hi = 1 - R_alpha_hi;\n\n// R_LP @ R_hiF (R_normalizado)\nR_lp_b0_h = ((1 - R_cos_hi) * 0.5) / R_a0_hi;\nR_lp_b1_h = (1 - R_cos_hi) / R_a0_hi;\nR_lp_b2_h = R_lp_b0_h;\nR_lp_a1_h = R_a1_hi / R_a0_hi;\nR_lp_a2_h = R_a2_hi / R_a0_hi;\n\n// R_HP @ R_hiF (R_normalizado)\nR_hp_b0_h = ((1 + R_cos_hi) * 0.5) / R_a0_hi;\nR_hp_b1_h = -(1 + R_cos_hi) / R_a0_hi;\nR_hp_b2_h = R_hp_b0_h;\nR_hp_a1_h = R_lp_a1_h;\nR_hp_a2_h = R_lp_a2_h;\n\n// ===== R_PRIMER R_CORTE @ R_loF: R_low (R_LP) R_y R_rest (R_HP) =====\n\n// R_LP R_Stage 1 R_para R_LOW\nR_l1_x1p = fixdenorm(R_l1_x1);\nR_l1_x2p = fixdenorm(R_l1_x2);\nR_l1_y1p = fixdenorm(R_l1_y1);\nR_l1_y2p = fixdenorm(R_l1_y2);\nR_low_s1 = R_lp_b0_l*R_x + R_lp_b1_l*R_l1_x1p + R_lp_b2_l*R_l1_x2p - R_lp_a1_l*R_l1_y1p - R_lp_a2_l*R_l1_y2p;\nR_l1_x2 = R_l1_x1p; R_l1_x1 = R_x; R_l1_y2 = R_l1_y1p; R_l1_y1 = R_low_s1;\n\n// R_LP R_Stage 2 R_para R_LOW\nR_l2_x1p = fixdenorm(R_l2_x1);\nR_l2_x2p = fixdenorm(R_l2_x2);\nR_l2_y1p = fixdenorm(R_l2_y1);\nR_l2_y2p = fixdenorm(R_l2_y2);\nR_low_raw = R_lp_b0_l*R_low_s1 + R_lp_b1_l*R_l2_x1p + R_lp_b2_l*R_l2_x2p - R_lp_a1_l*R_l2_y1p - R_lp_a2_l*R_l2_y2p;\nR_l2_x2 = R_l2_x1p; R_l2_x1 = R_low_s1; R_l2_y2 = R_l2_y1p; R_l2_y1 = R_low_raw;\n\n// R_HP R_Stage 1 R_para R_REST\nR_h1_x1p = fixdenorm(R_h1_x1);\nR_h1_x2p = fixdenorm(R_h1_x2);\nR_h1_y1p = fixdenorm(R_h1_y1);\nR_h1_y2p = fixdenorm(R_h1_y2);\nR_rest_s1 = R_hp_b0_l*R_x + R_hp_b1_l*R_h1_x1p + R_hp_b2_l*R_h1_x2p - R_hp_a1_l*R_h1_y1p - R_hp_a2_l*R_h1_y2p;\nR_h1_x2 = R_h1_x1p; R_h1_x1 = R_x; R_h1_y2 = R_h1_y1p; R_h1_y1 = R_rest_s1;\n\n// R_HP R_Stage 2 R_para R_REST\nR_h2_x1p = fixdenorm(R_h2_x1);\nR_h2_x2p = fixdenorm(R_h2_x2);\nR_h2_y1p = fixdenorm(R_h2_y1);\nR_h2_y2p = fixdenorm(R_h2_y2);\nR_rest = R_hp_b0_l*R_rest_s1 + R_hp_b1_l*R_h2_x1p + R_hp_b2_l*R_h2_x2p - R_hp_a1_l*R_h2_y1p - R_hp_a2_l*R_h2_y2p;\nR_h2_x2 = R_h2_x1p; R_h2_x1 = R_rest_s1; R_h2_y2 = R_h2_y1p; R_h2_y1 = R_rest;\n\n// ===== COMPENSACIÓN R_ALL-R_PASS R_para R_LOW =====\n// R_Aplicamos R_un R_all-R_pass R_LP+R_HP @ R_hiF R_a R_la señal R_LOW R_para R_igualar R_el R_delay\n\n// R_All-R_pass R_LP R_stage 1 R_sobre R_low_raw\nR_ap_low_lp1_x1p = fixdenorm(R_ap_low_lp1_x1);\nR_ap_low_lp1_x2p = fixdenorm(R_ap_low_lp1_x2);\nR_ap_low_lp1_y1p = fixdenorm(R_ap_low_lp1_y1);\nR_ap_low_lp1_y2p = fixdenorm(R_ap_low_lp1_y2);\nR_ap_low_lp_s1 = R_lp_b0_h*R_low_raw + R_lp_b1_h*R_ap_low_lp1_x1p + R_lp_b2_h*R_ap_low_lp1_x2p\n               - R_lp_a1_h*R_ap_low_lp1_y1p - R_lp_a2_h*R_ap_low_lp1_y2p;\nR_ap_low_lp1_x2 = R_ap_low_lp1_x1p; R_ap_low_lp1_x1 = R_low_raw;\nR_ap_low_lp1_y2 = R_ap_low_lp1_y1p; R_ap_low_lp1_y1 = R_ap_low_lp_s1;\n\n// R_All-R_pass R_LP R_stage 2\nR_ap_low_lp2_x1p = fixdenorm(R_ap_low_lp2_x1);\nR_ap_low_lp2_x2p = fixdenorm(R_ap_low_lp2_x2);\nR_ap_low_lp2_y1p = fixdenorm(R_ap_low_lp2_y1);\nR_ap_low_lp2_y2p = fixdenorm(R_ap_low_lp2_y2);\nR_ap_low_lp = R_lp_b0_h*R_ap_low_lp_s1 + R_lp_b1_h*R_ap_low_lp2_x1p + R_lp_b2_h*R_ap_low_lp2_x2p\n            - R_lp_a1_h*R_ap_low_lp2_y1p - R_lp_a2_h*R_ap_low_lp2_y2p;\nR_ap_low_lp2_x2 = R_ap_low_lp2_x1p; R_ap_low_lp2_x1 = R_ap_low_lp_s1;\nR_ap_low_lp2_y2 = R_ap_low_lp2_y1p; R_ap_low_lp2_y1 = R_ap_low_lp;\n\n// R_All-R_pass R_HP R_stage 1 R_sobre R_low_raw\nR_ap_low_hp1_x1p = fixdenorm(R_ap_low_hp1_x1);\nR_ap_low_hp1_x2p = fixdenorm(R_ap_low_hp1_x2);\nR_ap_low_hp1_y1p = fixdenorm(R_ap_low_hp1_y1);\nR_ap_low_hp1_y2p = fixdenorm(R_ap_low_hp1_y2);\nR_ap_low_hp_s1 = R_hp_b0_h*R_low_raw + R_hp_b1_h*R_ap_low_hp1_x1p + R_hp_b2_h*R_ap_low_hp1_x2p\n               - R_hp_a1_h*R_ap_low_hp1_y1p - R_hp_a2_h*R_ap_low_hp1_y2p;\nR_ap_low_hp1_x2 = R_ap_low_hp1_x1p; R_ap_low_hp1_x1 = R_low_raw;\nR_ap_low_hp1_y2 = R_ap_low_hp1_y1p; R_ap_low_hp1_y1 = R_ap_low_hp_s1;\n\n// R_All-R_pass R_HP R_stage 2\nR_ap_low_hp2_x1p = fixdenorm(R_ap_low_hp2_x1);\nR_ap_low_hp2_x2p = fixdenorm(R_ap_low_hp2_x2);\nR_ap_low_hp2_y1p = fixdenorm(R_ap_low_hp2_y1);\nR_ap_low_hp2_y2p = fixdenorm(R_ap_low_hp2_y2);\nR_ap_low_hp = R_hp_b0_h*R_ap_low_hp_s1 + R_hp_b1_h*R_ap_low_hp2_x1p + R_hp_b2_h*R_ap_low_hp2_x2p\n            - R_hp_a1_h*R_ap_low_hp2_y1p - R_hp_a2_h*R_ap_low_hp2_y2p;\nR_ap_low_hp2_x2 = R_ap_low_hp2_x1p; R_ap_low_hp2_x1 = R_ap_low_hp_s1;\nR_ap_low_hp2_y2 = R_ap_low_hp2_y1p; R_ap_low_hp2_y1 = R_ap_low_hp;\n\n// R_LOW R_compensado (R_all-R_pass R_reconstruye R_la señal R_con R_el R_mismo R_delay R_que R_mid/R_high)\nR_low = R_ap_low_lp + R_ap_low_hp;\n\n// ===== R_SEGUNDO R_CORTE @ R_hiF R_sobre R_REST: R_mid (R_LP) R_y R_high (R_HP) =====\n\n// R_LP R_Stage 1 R_para R_MID\nR_m1_x1p = fixdenorm(R_m1_x1);\nR_m1_x2p = fixdenorm(R_m1_x2);\nR_m1_y1p = fixdenorm(R_m1_y1);\nR_m1_y2p = fixdenorm(R_m1_y2);\nR_mid_s1 = R_lp_b0_h*R_rest + R_lp_b1_h*R_m1_x1p + R_lp_b2_h*R_m1_x2p - R_lp_a1_h*R_m1_y1p - R_lp_a2_h*R_m1_y2p;\nR_m1_x2 = R_m1_x1p; R_m1_x1 = R_rest; R_m1_y2 = R_m1_y1p; R_m1_y1 = R_mid_s1;\n\n// R_LP R_Stage 2 R_para R_MID\nR_m2_x1p = fixdenorm(R_m2_x1);\nR_m2_x2p = fixdenorm(R_m2_x2);\nR_m2_y1p = fixdenorm(R_m2_y1);\nR_m2_y2p = fixdenorm(R_m2_y2);\nR_mid = R_lp_b0_h*R_mid_s1 + R_lp_b1_h*R_m2_x1p + R_lp_b2_h*R_m2_x2p - R_lp_a1_h*R_m2_y1p - R_lp_a2_h*R_m2_y2p;\nR_m2_x2 = R_m2_x1p; R_m2_x1 = R_mid_s1; R_m2_y2 = R_m2_y1p; R_m2_y1 = R_mid;\n\n// R_HP R_Stage 1 R_para R_HIGH\nR_u1_x1p = fixdenorm(R_u1_x1);\nR_u1_x2p = fixdenorm(R_u1_x2);\nR_u1_y1p = fixdenorm(R_u1_y1);\nR_u1_y2p = fixdenorm(R_u1_y2);\nR_high_s1 = R_hp_b0_h*R_rest + R_hp_b1_h*R_u1_x1p + R_hp_b2_h*R_u1_x2p - R_hp_a1_h*R_u1_y1p - R_hp_a2_h*R_u1_y2p;\nR_u1_x2 = R_u1_x1p; R_u1_x1 = R_rest; R_u1_y2 = R_u1_y1p; R_u1_y1 = R_high_s1;\n\n// R_HP R_Stage 2 R_para R_HIGH\nR_u2_x1p = fixdenorm(R_u2_x1);\nR_u2_x2p = fixdenorm(R_u2_x2);\nR_u2_y1p = fixdenorm(R_u2_y1);\nR_u2_y2p = fixdenorm(R_u2_y2);\nR_high = R_hp_b0_h*R_high_s1 + R_hp_b1_h*R_u2_x1p + R_hp_b2_h*R_u2_x2p - R_hp_a1_h*R_u2_y1p - R_hp_a2_h*R_u2_y2p;\nR_u2_x2 = R_u2_x1p; R_u2_x1 = R_high_s1; R_u2_y2 = R_u2_y1p; R_u2_y1 = R_high;\n\n// ===== R_SALIDAS =====\nlowR = R_low;   // R_Graves R_compensados\nmidR = R_mid;   // R_Medios\nhighR = R_high;  // R_Agudos\n\n\n// Selector de banda (0=low, 1=mid, 2=high) con suavizado (smoothedBand)\nwLow = max(0, 1 - abs(smoothedBand - 0));\nwMid = max(0, 1 - abs(smoothedBand - 1));\nwHigh = max(0, 1 - abs(smoothedBand - 2));\nwSum = max(1e-9, wLow + wMid + wHigh);\nwLow /= wSum; wMid /= wSum; wHigh /= wSum;\n\n// Banda a procesar y suma limpia para recomponer\npreBandL = wLow*lowL + wMid*midL + wHigh*highL;\npreBandR = wLow*lowR + wMid*midR + wHigh*highR;\nsumBandsL = lowL + midL + highL;\nsumBandsR = lowR + midR + highR;\n\n// Solo activo solo tiene sentido con el crossover activo (scSm ~1)\n//soloOn = (wBandSolo > 0.5) * (scSm > 0.5);\n// Si Solo está ON: las otras bandas NO pasan al WET por bypassWhenActive\n//bypassWhenActiveL = soloOn ? 0 : (sumBandsL - preBandL);\n//bypassWhenActiveR = soloOn ? 0 : (sumBandsR - preBandR);\n\n// Solo como cantidad continua (0..1), ya suavizada, y dependiente del crossover\nsoloAmt = clamp(hBandSolo * scSm, 0, 1);\n// Atenúa progresivamente lo que NO es la banda seleccionada\nbypassWhenActiveL = (sumBandsL - preBandL) * (1 - soloAmt);\nbypassWhenActiveR = (sumBandsR - preBandR) * (1 - soloAmt);\n\n// Conmutación por enable (scSm): si desactivado, banda ancha\npreDistInL = mix(lTrimmed, preBandL, scSm);\npreDistInR = mix(rTrimmed, preBandR, scSm);\n\n// Allpass de compensación solo para la rama dry cuando crossover activo\n// === L_AP bindings ===\nL_loF = smoothHpfFreq;\nL_hiF = smoothLpfFreq;\n// L_All-L_pass L_LR4 L_de compensación L_para L_null L_test L_externo\n// L_Aplica L_el L_mismo L_delay L_de L_grupo L_que L_el L_crossover L_LR4\n// L_Para L_usar L_en L_la línea L_dry L_fuera L_del L_crossover\n\n// Parámetros (L_deben L_coincidir L_con L_los L_del L_crossover)\n// L_Estados L_para L_primer L_all-L_pass @ L_loF\n// L_Estados L_para L_segundo L_all-L_pass @ L_hiF\n\n// L_Entrada\n//L_x = lTrimmed;\n// L_Entrada (PRE-TRIM)\nL_x = lIn;\n\n// L_Constantes\nL_QBW = 0.7071067811865476; // sqrt(2)/2 L_para L_Butterworth\n\n// L_Proteger L_frecuencias\nL_sr = samplerate;\nL_loF = max(10, min(L_loF, 0.45 * L_sr));\nL_hiFr = max(10, min(L_hiF, 0.45 * L_sr));\nL_hiF = max(L_hiFr, L_loF + 1);\n\n// === L_Coeficientes L_Butterworth @ L_loF ===\nL_w0_lo = TWOPI * L_loF / L_sr;\nL_cos_lo = cos(L_w0_lo);\nL_sin_lo = sin(L_w0_lo);\nL_alpha_lo = L_sin_lo / (2 * L_QBW);\nL_a0_lo = 1 + L_alpha_lo;\nL_a1_lo = -2 * L_cos_lo;\nL_a2_lo = 1 - L_alpha_lo;\n\n// L_LP @ L_loF (L_normalizado)\nL_lp_b0_l = ((1 - L_cos_lo) * 0.5) / L_a0_lo;\nL_lp_b1_l = (1 - L_cos_lo) / L_a0_lo;\nL_lp_b2_l = L_lp_b0_l;\nL_lp_a1_l = L_a1_lo / L_a0_lo;\nL_lp_a2_l = L_a2_lo / L_a0_lo;\n\n// L_HP @ L_loF (L_normalizado)\nL_hp_b0_l = ((1 + L_cos_lo) * 0.5) / L_a0_lo;\nL_hp_b1_l = -(1 + L_cos_lo) / L_a0_lo;\nL_hp_b2_l = L_hp_b0_l;\nL_hp_a1_l = L_lp_a1_l;\nL_hp_a2_l = L_lp_a2_l;\n\n// === L_Coeficientes L_Butterworth @ L_hiF ===\nL_w0_hi = TWOPI * L_hiF / L_sr;\nL_cos_hi = cos(L_w0_hi);\nL_sin_hi = sin(L_w0_hi);\nL_alpha_hi = L_sin_hi / (2 * L_QBW);\nL_a0_hi = 1 + L_alpha_hi;\nL_a1_hi = -2 * L_cos_hi;\nL_a2_hi = 1 - L_alpha_hi;\n\n// L_LP @ L_hiF (L_normalizado)\nL_lp_b0_h = ((1 - L_cos_hi) * 0.5) / L_a0_hi;\nL_lp_b1_h = (1 - L_cos_hi) / L_a0_hi;\nL_lp_b2_h = L_lp_b0_h;\nL_lp_a1_h = L_a1_hi / L_a0_hi;\nL_lp_a2_h = L_a2_hi / L_a0_hi;\n\n// L_HP @ L_hiF (L_normalizado)\nL_hp_b0_h = ((1 + L_cos_hi) * 0.5) / L_a0_hi;\nL_hp_b1_h = -(1 + L_cos_hi) / L_a0_hi;\nL_hp_b2_h = L_hp_b0_h;\nL_hp_a1_h = L_lp_a1_h;\nL_hp_a2_h = L_lp_a2_h;\n\n// === L_PRIMER L_ALL-L_PASS @ L_loF ===\n// L_LP L_Stage 1\nL_ap1_lp1_x1p = L_ap1_lp1_x1; L_ap1_lp1_x2p = L_ap1_lp1_x2;\nL_ap1_lp1_y1p = L_ap1_lp1_y1; L_ap1_lp1_y2p = L_ap1_lp1_y2;\nL_ap1_lp_s1 = L_lp_b0_l*L_x + L_lp_b1_l*L_ap1_lp1_x1p + L_lp_b2_l*L_ap1_lp1_x2p\n            - L_lp_a1_l*L_ap1_lp1_y1p - L_lp_a2_l*L_ap1_lp1_y2p;\nL_ap1_lp1_x2 = L_ap1_lp1_x1p; L_ap1_lp1_x1 = L_x;\nL_ap1_lp1_y2 = L_ap1_lp1_y1p; L_ap1_lp1_y1 = L_ap1_lp_s1;\n\n// L_LP L_Stage 2\nL_ap1_lp2_x1p = L_ap1_lp2_x1; L_ap1_lp2_x2p = L_ap1_lp2_x2;\nL_ap1_lp2_y1p = L_ap1_lp2_y1; L_ap1_lp2_y2p = L_ap1_lp2_y2;\nL_ap1_lp = L_lp_b0_l*L_ap1_lp_s1 + L_lp_b1_l*L_ap1_lp2_x1p + L_lp_b2_l*L_ap1_lp2_x2p\n         - L_lp_a1_l*L_ap1_lp2_y1p - L_lp_a2_l*L_ap1_lp2_y2p;\nL_ap1_lp2_x2 = L_ap1_lp2_x1p; L_ap1_lp2_x1 = L_ap1_lp_s1;\nL_ap1_lp2_y2 = L_ap1_lp2_y1p; L_ap1_lp2_y1 = L_ap1_lp;\n\n// L_HP L_Stage 1\nL_ap1_hp1_x1p = L_ap1_hp1_x1; L_ap1_hp1_x2p = L_ap1_hp1_x2;\nL_ap1_hp1_y1p = L_ap1_hp1_y1; L_ap1_hp1_y2p = L_ap1_hp1_y2;\nL_ap1_hp_s1 = L_hp_b0_l*L_x + L_hp_b1_l*L_ap1_hp1_x1p + L_hp_b2_l*L_ap1_hp1_x2p\n            - L_hp_a1_l*L_ap1_hp1_y1p - L_hp_a2_l*L_ap1_hp1_y2p;\nL_ap1_hp1_x2 = L_ap1_hp1_x1p; L_ap1_hp1_x1 = L_x;\nL_ap1_hp1_y2 = L_ap1_hp1_y1p; L_ap1_hp1_y1 = L_ap1_hp_s1;\n\n// L_HP L_Stage 2\nL_ap1_hp2_x1p = L_ap1_hp2_x1; L_ap1_hp2_x2p = L_ap1_hp2_x2;\nL_ap1_hp2_y1p = L_ap1_hp2_y1; L_ap1_hp2_y2p = L_ap1_hp2_y2;\nL_ap1_hp = L_hp_b0_l*L_ap1_hp_s1 + L_hp_b1_l*L_ap1_hp2_x1p + L_hp_b2_l*L_ap1_hp2_x2p\n         - L_hp_a1_l*L_ap1_hp2_y1p - L_hp_a2_l*L_ap1_hp2_y2p;\nL_ap1_hp2_x2 = L_ap1_hp2_x1p; L_ap1_hp2_x1 = L_ap1_hp_s1;\nL_ap1_hp2_y2 = L_ap1_hp2_y1p; L_ap1_hp2_y1 = L_ap1_hp;\n\n// L_Reconstruir L_primer L_all-L_pass\nL_stage1_out = L_ap1_lp + L_ap1_hp;\n\n// === L_SEGUNDO L_ALL-L_PASS @ L_hiF ===\n// L_LP L_Stage 1\nL_ap2_lp1_x1p = L_ap2_lp1_x1; L_ap2_lp1_x2p = L_ap2_lp1_x2;\nL_ap2_lp1_y1p = L_ap2_lp1_y1; L_ap2_lp1_y2p = L_ap2_lp1_y2;\nL_ap2_lp_s1 = L_lp_b0_h*L_stage1_out + L_lp_b1_h*L_ap2_lp1_x1p + L_lp_b2_h*L_ap2_lp1_x2p\n            - L_lp_a1_h*L_ap2_lp1_y1p - L_lp_a2_h*L_ap2_lp1_y2p;\nL_ap2_lp1_x2 = L_ap2_lp1_x1p; L_ap2_lp1_x1 = L_stage1_out;\nL_ap2_lp1_y2 = L_ap2_lp1_y1p; L_ap2_lp1_y1 = L_ap2_lp_s1;\n\n// L_LP L_Stage 2\nL_ap2_lp2_x1p = L_ap2_lp2_x1; L_ap2_lp2_x2p = L_ap2_lp2_x2;\nL_ap2_lp2_y1p = L_ap2_lp2_y1; L_ap2_lp2_y2p = L_ap2_lp2_y2;\nL_ap2_lp = L_lp_b0_h*L_ap2_lp_s1 + L_lp_b1_h*L_ap2_lp2_x1p + L_lp_b2_h*L_ap2_lp2_x2p\n         - L_lp_a1_h*L_ap2_lp2_y1p - L_lp_a2_h*L_ap2_lp2_y2p;\nL_ap2_lp2_x2 = L_ap2_lp2_x1p; L_ap2_lp2_x1 = L_ap2_lp_s1;\nL_ap2_lp2_y2 = L_ap2_lp2_y1p; L_ap2_lp2_y1 = L_ap2_lp;\n\n// L_HP L_Stage 1\nL_ap2_hp1_x1p = L_ap2_hp1_x1; L_ap2_hp1_x2p = L_ap2_hp1_x2;\nL_ap2_hp1_y1p = L_ap2_hp1_y1; L_ap2_hp1_y2p = L_ap2_hp1_y2;\nL_ap2_hp_s1 = L_hp_b0_h*L_stage1_out + L_hp_b1_h*L_ap2_hp1_x1p + L_hp_b2_h*L_ap2_hp1_x2p\n            - L_hp_a1_h*L_ap2_hp1_y1p - L_hp_a2_h*L_ap2_hp1_y2p;\nL_ap2_hp1_x2 = L_ap2_hp1_x1p; L_ap2_hp1_x1 = L_stage1_out;\nL_ap2_hp1_y2 = L_ap2_hp1_y1p; L_ap2_hp1_y1 = L_ap2_hp_s1;\n\n// L_HP L_Stage 2\nL_ap2_hp2_x1p = L_ap2_hp2_x1; L_ap2_hp2_x2p = L_ap2_hp2_x2;\nL_ap2_hp2_y1p = L_ap2_hp2_y1; L_ap2_hp2_y2p = L_ap2_hp2_y2;\nL_ap2_hp = L_hp_b0_h*L_ap2_hp_s1 + L_hp_b1_h*L_ap2_hp2_x1p + L_hp_b2_h*L_ap2_hp2_x2p\n         - L_hp_a1_h*L_ap2_hp2_y1p - L_hp_a2_h*L_ap2_hp2_y2p;\nL_ap2_hp2_x2 = L_ap2_hp2_x1p; L_ap2_hp2_x1 = L_ap2_hp_s1;\nL_ap2_hp2_y2 = L_ap2_hp2_y1p; L_ap2_hp2_y1 = L_ap2_hp;\n\n// L_Salida: señal L_con L_el L_mismo L_delay L_que L_el L_crossover L_LR4\ndryCompL = L_ap2_lp + L_ap2_hp;\n// === R_AP bindings ===\nR_loF = smoothHpfFreq;\nR_hiF = smoothLpfFreq;\n// R_All-R_pass R_LR4 R_de compensación R_para R_null R_test R_externo\n// R_Aplica R_el R_mismo R_delay R_de R_grupo R_que R_el R_crossover R_LR4\n// R_Para R_usar R_en R_la línea R_dry R_fuera R_del R_crossover\n\n// Parámetros (R_deben R_coincidir R_con R_los R_del R_crossover)\n// R_Estados R_para R_primer R_all-R_pass @ R_loF\n// R_Estados R_para R_segundo R_all-R_pass @ R_hiF\n\n// R_Entrada\n//R_x = rTrimmed;\n// R_Entrada (PRE-TRIM)\nR_x = rIn;\n\n// R_Constantes\nR_QBW = 0.7071067811865476; // sqrt(2)/2 R_para R_Butterworth\n\n// R_Proteger R_frecuencias\nR_sr = samplerate;\nR_loF = max(10, min(R_loF, 0.45 * R_sr));\nR_hiFr = max(10, min(R_hiF, 0.45 * R_sr));\nR_hiF = max(R_hiFr, R_loF + 1);\n\n// === R_Coeficientes R_Butterworth @ R_loF ===\nR_w0_lo = TWOPI * R_loF / R_sr;\nR_cos_lo = cos(R_w0_lo);\nR_sin_lo = sin(R_w0_lo);\nR_alpha_lo = R_sin_lo / (2 * R_QBW);\nR_a0_lo = 1 + R_alpha_lo;\nR_a1_lo = -2 * R_cos_lo;\nR_a2_lo = 1 - R_alpha_lo;\n\n// R_LP @ R_loF (R_normalizado)\nR_lp_b0_l = ((1 - R_cos_lo) * 0.5) / R_a0_lo;\nR_lp_b1_l = (1 - R_cos_lo) / R_a0_lo;\nR_lp_b2_l = R_lp_b0_l;\nR_lp_a1_l = R_a1_lo / R_a0_lo;\nR_lp_a2_l = R_a2_lo / R_a0_lo;\n\n// R_HP @ R_loF (R_normalizado)\nR_hp_b0_l = ((1 + R_cos_lo) * 0.5) / R_a0_lo;\nR_hp_b1_l = -(1 + R_cos_lo) / R_a0_lo;\nR_hp_b2_l = R_hp_b0_l;\nR_hp_a1_l = R_lp_a1_l;\nR_hp_a2_l = R_lp_a2_l;\n\n// === R_Coeficientes R_Butterworth @ R_hiF ===\nR_w0_hi = TWOPI * R_hiF / R_sr;\nR_cos_hi = cos(R_w0_hi);\nR_sin_hi = sin(R_w0_hi);\nR_alpha_hi = R_sin_hi / (2 * R_QBW);\nR_a0_hi = 1 + R_alpha_hi;\nR_a1_hi = -2 * R_cos_hi;\nR_a2_hi = 1 - R_alpha_hi;\n\n// R_LP @ R_hiF (R_normalizado)\nR_lp_b0_h = ((1 - R_cos_hi) * 0.5) / R_a0_hi;\nR_lp_b1_h = (1 - R_cos_hi) / R_a0_hi;\nR_lp_b2_h = R_lp_b0_h;\nR_lp_a1_h = R_a1_hi / R_a0_hi;\nR_lp_a2_h = R_a2_hi / R_a0_hi;\n\n// R_HP @ R_hiF (R_normalizado)\nR_hp_b0_h = ((1 + R_cos_hi) * 0.5) / R_a0_hi;\nR_hp_b1_h = -(1 + R_cos_hi) / R_a0_hi;\nR_hp_b2_h = R_hp_b0_h;\nR_hp_a1_h = R_lp_a1_h;\nR_hp_a2_h = R_lp_a2_h;\n\n// === R_PRIMER R_ALL-R_PASS @ R_loF ===\n// R_LP R_Stage 1\nR_ap1_lp1_x1p = R_ap1_lp1_x1; R_ap1_lp1_x2p = R_ap1_lp1_x2;\nR_ap1_lp1_y1p = R_ap1_lp1_y1; R_ap1_lp1_y2p = R_ap1_lp1_y2;\nR_ap1_lp_s1 = R_lp_b0_l*R_x + R_lp_b1_l*R_ap1_lp1_x1p + R_lp_b2_l*R_ap1_lp1_x2p\n            - R_lp_a1_l*R_ap1_lp1_y1p - R_lp_a2_l*R_ap1_lp1_y2p;\nR_ap1_lp1_x2 = R_ap1_lp1_x1p; R_ap1_lp1_x1 = R_x;\nR_ap1_lp1_y2 = R_ap1_lp1_y1p; R_ap1_lp1_y1 = R_ap1_lp_s1;\n\n// R_LP R_Stage 2\nR_ap1_lp2_x1p = R_ap1_lp2_x1; R_ap1_lp2_x2p = R_ap1_lp2_x2;\nR_ap1_lp2_y1p = R_ap1_lp2_y1; R_ap1_lp2_y2p = R_ap1_lp2_y2;\nR_ap1_lp = R_lp_b0_l*R_ap1_lp_s1 + R_lp_b1_l*R_ap1_lp2_x1p + R_lp_b2_l*R_ap1_lp2_x2p\n         - R_lp_a1_l*R_ap1_lp2_y1p - R_lp_a2_l*R_ap1_lp2_y2p;\nR_ap1_lp2_x2 = R_ap1_lp2_x1p; R_ap1_lp2_x1 = R_ap1_lp_s1;\nR_ap1_lp2_y2 = R_ap1_lp2_y1p; R_ap1_lp2_y1 = R_ap1_lp;\n\n// R_HP R_Stage 1\nR_ap1_hp1_x1p = R_ap1_hp1_x1; R_ap1_hp1_x2p = R_ap1_hp1_x2;\nR_ap1_hp1_y1p = R_ap1_hp1_y1; R_ap1_hp1_y2p = R_ap1_hp1_y2;\nR_ap1_hp_s1 = R_hp_b0_l*R_x + R_hp_b1_l*R_ap1_hp1_x1p + R_hp_b2_l*R_ap1_hp1_x2p\n            - R_hp_a1_l*R_ap1_hp1_y1p - R_hp_a2_l*R_ap1_hp1_y2p;\nR_ap1_hp1_x2 = R_ap1_hp1_x1p; R_ap1_hp1_x1 = R_x;\nR_ap1_hp1_y2 = R_ap1_hp1_y1p; R_ap1_hp1_y1 = R_ap1_hp_s1;\n\n// R_HP R_Stage 2\nR_ap1_hp2_x1p = R_ap1_hp2_x1; R_ap1_hp2_x2p = R_ap1_hp2_x2;\nR_ap1_hp2_y1p = R_ap1_hp2_y1; R_ap1_hp2_y2p = R_ap1_hp2_y2;\nR_ap1_hp = R_hp_b0_l*R_ap1_hp_s1 + R_hp_b1_l*R_ap1_hp2_x1p + R_hp_b2_l*R_ap1_hp2_x2p\n         - R_hp_a1_l*R_ap1_hp2_y1p - R_hp_a2_l*R_ap1_hp2_y2p;\nR_ap1_hp2_x2 = R_ap1_hp2_x1p; R_ap1_hp2_x1 = R_ap1_hp_s1;\nR_ap1_hp2_y2 = R_ap1_hp2_y1p; R_ap1_hp2_y1 = R_ap1_hp;\n\n// R_Reconstruir R_primer R_all-R_pass\nR_stage1_out = R_ap1_lp + R_ap1_hp;\n\n// === R_SEGUNDO R_ALL-R_PASS @ R_hiF ===\n// R_LP R_Stage 1\nR_ap2_lp1_x1p = R_ap2_lp1_x1; R_ap2_lp1_x2p = R_ap2_lp1_x2;\nR_ap2_lp1_y1p = R_ap2_lp1_y1; R_ap2_lp1_y2p = R_ap2_lp1_y2;\nR_ap2_lp_s1 = R_lp_b0_h*R_stage1_out + R_lp_b1_h*R_ap2_lp1_x1p + R_lp_b2_h*R_ap2_lp1_x2p\n            - R_lp_a1_h*R_ap2_lp1_y1p - R_lp_a2_h*R_ap2_lp1_y2p;\nR_ap2_lp1_x2 = R_ap2_lp1_x1p; R_ap2_lp1_x1 = R_stage1_out;\nR_ap2_lp1_y2 = R_ap2_lp1_y1p; R_ap2_lp1_y1 = R_ap2_lp_s1;\n\n// R_LP R_Stage 2\nR_ap2_lp2_x1p = R_ap2_lp2_x1; R_ap2_lp2_x2p = R_ap2_lp2_x2;\nR_ap2_lp2_y1p = R_ap2_lp2_y1; R_ap2_lp2_y2p = R_ap2_lp2_y2;\nR_ap2_lp = R_lp_b0_h*R_ap2_lp_s1 + R_lp_b1_h*R_ap2_lp2_x1p + R_lp_b2_h*R_ap2_lp2_x2p\n         - R_lp_a1_h*R_ap2_lp2_y1p - R_lp_a2_h*R_ap2_lp2_y2p;\nR_ap2_lp2_x2 = R_ap2_lp2_x1p; R_ap2_lp2_x1 = R_ap2_lp_s1;\nR_ap2_lp2_y2 = R_ap2_lp2_y1p; R_ap2_lp2_y1 = R_ap2_lp;\n\n// R_HP R_Stage 1\nR_ap2_hp1_x1p = R_ap2_hp1_x1; R_ap2_hp1_x2p = R_ap2_hp1_x2;\nR_ap2_hp1_y1p = R_ap2_hp1_y1; R_ap2_hp1_y2p = R_ap2_hp1_y2;\nR_ap2_hp_s1 = R_hp_b0_h*R_stage1_out + R_hp_b1_h*R_ap2_hp1_x1p + R_hp_b2_h*R_ap2_hp1_x2p\n            - R_hp_a1_h*R_ap2_hp1_y1p - R_hp_a2_h*R_ap2_hp1_y2p;\nR_ap2_hp1_x2 = R_ap2_hp1_x1p; R_ap2_hp1_x1 = R_stage1_out;\nR_ap2_hp1_y2 = R_ap2_hp1_y1p; R_ap2_hp1_y1 = R_ap2_hp_s1;\n\n// R_HP R_Stage 2\nR_ap2_hp2_x1p = R_ap2_hp2_x1; R_ap2_hp2_x2p = R_ap2_hp2_x2;\nR_ap2_hp2_y1p = R_ap2_hp2_y1; R_ap2_hp2_y2p = R_ap2_hp2_y2;\nR_ap2_hp = R_hp_b0_h*R_ap2_hp_s1 + R_hp_b1_h*R_ap2_hp2_x1p + R_hp_b2_h*R_ap2_hp2_x2p\n         - R_hp_a1_h*R_ap2_hp2_y1p - R_hp_a2_h*R_ap2_hp2_y2p;\nR_ap2_hp2_x2 = R_ap2_hp2_x1p; R_ap2_hp2_x1 = R_ap2_hp_s1;\nR_ap2_hp2_y2 = R_ap2_hp2_y1p; R_ap2_hp2_y1 = R_ap2_hp;\n\n// R_Salida: señal R_con R_el R_mismo R_delay R_que R_el R_crossover R_LR4\ndryCompR = R_ap2_lp + R_ap2_hp;\ndryL = mix(lIn, dryCompL, scSm);\ndryR = mix(rIn, dryCompR, scSm);\n\n// Entrada al bloque de TILT\nlLs = preDistInL;\nrLs = preDistInR;\n\n// Mapeo para TILT: usar la señal seleccionada por el crossover\nlFiltered = preDistInL;\nrFiltered = preDistInR;\n\n// -----------------------------------------------------------------------------\n// FILTRO TILT PRE-DISTORSIÓN\n// -----------------------------------------------------------------------------\nfc = 1000.0;     // 1 kHz como pivote del tilt\n// q ya no se usa en la versión RBJ del tilt (S=1 internamente)\n\n// Cálculo de coeficientes para Tilt (invertido para UI intuitiva)\n//tiltGain = dbtoa(-tiltDb);\n//omega = (fc * twopi) / samplerate;\n//sn = sin(omega);\n//cs = cos(omega);\n//A = sqrt(tiltGain);\n//beta = sqrt((A * A + 1) / q - (A - 1) * (A - 1));\n\n// RBJ cookbook prep (tilt = LS(-G) + HS(+G))\nomega = (fc * twopi) / samplerate;\nsn = sin(omega);\ncs = cos(omega);\n\n// Ganancias complementarias en dB\nGls = -tiltDb;               // Low-shelf: -G\nGhs =  tiltDb;               // High-shelf: +G\n\n// A = 10^(G/40)\nAls = sqrt(dbtoa(Gls));\nAhs = sqrt(dbtoa(Ghs));\n\n// Slope RBJ (S=1 es canónico y estable)\nS  = 0.5; //1.0;\n\n// alpha para shelves (RBJ)\nalphaLs = 0.5 * sn * sqrt((Als + 1/Als) * (1/S - 1) + 2);\nalphaHs = 0.5 * sn * sqrt((Ahs + 1/Ahs) * (1/S - 1) + 2);\n\n// raíces de A (se usan en los términos 2*sqrt(A)*alpha)\nsqrtAls = sqrt(Als);\nsqrtAhs = sqrt(Ahs);\n\n// Coeficientes Low Shelf\n//b0Ls = 1 / ((A + 1) + (A - 1) * cs + beta * sn);\n//a0Ls = A * ((A + 1) - (A - 1) * cs + beta * sn) * b0Ls;\n//a1Ls = 2 * A * ((A - 1) - (A + 1) * cs) * b0Ls;\n//a2Ls = A * ((A + 1) - (A - 1) * cs - beta * sn) * b0Ls;\n//b1Ls = -2 * ((A - 1) + (A + 1) * cs) * b0Ls;\n//b2Ls = ((A + 1) + (A - 1) * cs - beta * sn) * b0Ls;\n\n// RBJ Low-Shelf (normalizado a a0)\nb0_ls =  Als * ((Als + 1) - (Als - 1) * cs + 2 * sqrtAls * alphaLs);\nb1_ls = 2*Als * ((Als - 1) - (Als + 1) * cs);\nb2_ls =  Als * ((Als + 1) - (Als - 1) * cs - 2 * sqrtAls * alphaLs);\n\na0_ls =        (Als + 1) + (Als - 1) * cs + 2 * sqrtAls * alphaLs;\na1_ls =   -2 * ((Als - 1) + (Als + 1) * cs);\na2_ls =        (Als + 1) + (Als - 1) * cs - 2 * sqrtAls * alphaLs;\n\n// Normalización\ninv_a0_ls = 1 / a0_ls;\na0Ls = b0_ls * inv_a0_ls;\na1Ls = b1_ls * inv_a0_ls;\na2Ls = b2_ls * inv_a0_ls;\nb1Ls = a1_ls * inv_a0_ls;\nb2Ls = a2_ls * inv_a0_ls;\n\n// Aplicar Low Shelf\n//lLs = a0Ls * lFiltered + a1Ls * tiltL2 + a2Ls * tiltL1 - b1Ls * tiltL4 - b2Ls * tiltL3;\n//tiltL1 = tiltL2;\n//tiltL2 = lFiltered;\n//tiltL3 = tiltL4;\n//tiltL4 = lLs;\n\n//rLs = a0Ls * rFiltered + a1Ls * tiltR2 + a2Ls * tiltR1 - b1Ls * tiltR4 - b2Ls * tiltR3;\n//tiltR1 = tiltR2;\n//tiltR2 = rFiltered;\n//tiltR3 = tiltR4;\n//tiltR4 = rLs;\n\n// Aplicar Low Shelf\nlLs = a0Ls * lFiltered\n    + a1Ls * fixdenorm(tiltLsL2)\n    + a2Ls * fixdenorm(tiltLsL1)\n    - b1Ls * fixdenorm(tiltLsL4)\n    - b2Ls * fixdenorm(tiltLsL3);\ntiltLsL1 = tiltLsL2;   // x2 ← x1\ntiltLsL2 = lFiltered;  // x1 ← x\ntiltLsL3 = tiltLsL4;   // y2 ← y1\ntiltLsL4 = lLs;        // y1 ← y\n\nrLs = a0Ls * rFiltered\n    + a1Ls * fixdenorm(tiltLsR2)\n    + a2Ls * fixdenorm(tiltLsR1)\n    - b1Ls * fixdenorm(tiltLsR4)\n    - b2Ls * fixdenorm(tiltLsR3);\ntiltLsR1 = tiltLsR2;\ntiltLsR2 = rFiltered;\ntiltLsR3 = tiltLsR4;\ntiltLsR4 = rLs;\n\n// Coeficientes High Shelf\n//aInv = sqrt(1/tiltGain);\n//betaHs = sqrt((aInv * aInv + 1) / q - (aInv - 1) * (aInv - 1));\n//b0Hs = 1 / ((aInv + 1) - (aInv - 1) * cs + betaHs * sn);\n//a0Hs = aInv * ((aInv + 1) + (aInv - 1) * cs + betaHs * sn) * b0Hs;\n//a1Hs = -2 * aInv * ((aInv - 1) + (aInv + 1) * cs) * b0Hs;\n//a2Hs = aInv * ((aInv + 1) + (aInv - 1) * cs - betaHs * sn) * b0Hs;\n//b1Hs = 2 * ((aInv - 1) - (aInv + 1) * cs) * b0Hs;\n//b2Hs = ((aInv + 1) - (aInv - 1) * cs - betaHs * sn) * b0Hs;\n\n// RBJ High-Shelf (normalizado a a0)\nb0_hs =  Ahs * ((Ahs + 1) + (Ahs - 1) * cs + 2 * sqrtAhs * alphaHs);\nb1_hs = -2*Ahs * ((Ahs - 1) + (Ahs + 1) * cs);\nb2_hs =  Ahs * ((Ahs + 1) + (Ahs - 1) * cs - 2 * sqrtAhs * alphaHs);\n\na0_hs =        (Ahs + 1) - (Ahs - 1) * cs + 2 * sqrtAhs * alphaHs;\na1_hs =    2 * ((Ahs - 1) - (Ahs + 1) * cs);\na2_hs =        (Ahs + 1) - (Ahs - 1) * cs - 2 * sqrtAhs * alphaHs;\n\n// Normalización\ninv_a0_hs = 1 / a0_hs;\na0Hs = b0_hs * inv_a0_hs;\na1Hs = b1_hs * inv_a0_hs;\na2Hs = b2_hs * inv_a0_hs;\nb1Hs = a1_hs * inv_a0_hs;\nb2Hs = a2_hs * inv_a0_hs;\n\n//lTilt = a0Hs * lLs + a1Hs * tiltL2 + a2Hs * tiltL1 - b1Hs * tiltL4 - b2Hs * tiltL3;\n//rTilt = a0Hs * rLs + a1Hs * tiltR2 + a2Hs * tiltR1 - b1Hs * tiltR4 - b2Hs * tiltR3;\n\nlTiltRaw = a0Hs * lLs\n         + a1Hs * fixdenorm(tiltHsL2)\n         + a2Hs * fixdenorm(tiltHsL1)\n         - b1Hs * fixdenorm(tiltHsL4)\n         - b2Hs * fixdenorm(tiltHsL3);\ntiltHsL1 = tiltHsL2;\ntiltHsL2 = lLs;\ntiltHsL3 = tiltHsL4;\ntiltHsL4 = lTiltRaw;\n\nrTiltRaw = a0Hs * rLs\n         + a1Hs * fixdenorm(tiltHsR2)\n         + a2Hs * fixdenorm(tiltHsR1)\n         - b1Hs * fixdenorm(tiltHsR4)\n         - b2Hs * fixdenorm(tiltHsR3);\ntiltHsR1 = tiltHsR2;\ntiltHsR2 = rLs;\ntiltHsR3 = tiltHsR4;\ntiltHsR4 = rTiltRaw;\n\n// Salida del bloque TILT (sin normalización aún)\n//lTilt = lTiltRaw;\n//rTilt = rTiltRaw;\n\n// Normalización en el pivote (fc)\ncosw = cs;           // ya calculados arriba\nsinw = sn;\ncos2 = (cs*cs - sn*sn);\nsin2 = (2*sn*cs);\n\n// Magnitud LS en fc\nnr_ls = a0Ls + a1Ls*cosw + a2Ls*cos2;\nni_ls = -(a1Ls*sinw + a2Ls*sin2);\ndr_ls = 1 + b1Ls*cosw + b2Ls*cos2;\ndi_ls = -(b1Ls*sinw + b2Ls*sin2);\nmag2_ls = (nr_ls*nr_ls + ni_ls*ni_ls) / max(1e-12, (dr_ls*dr_ls + di_ls*di_ls));\nmag_ls = sqrt(mag2_ls);\n\n// Magnitud HS en fc\nnr_hs = a0Hs + a1Hs*cosw + a2Hs*cos2;\nni_hs = -(a1Hs*sinw + a2Hs*sin2);\ndr_hs = 1 + b1Hs*cosw + b2Hs*cos2;\ndi_hs = -(b1Hs*sinw + b2Hs*sin2);\nmag2_hs = (nr_hs*nr_hs + ni_hs*ni_hs) / max(1e-12, (dr_hs*dr_hs + di_hs*di_hs));\nmag_hs = sqrt(mag2_hs);\n\n// Ganancia de normalización\ngPivot = 1 / max(1e-9, mag_ls * mag_hs);\n\n// Salida normalizada\nlTilt = lTiltRaw * gPivot;\nrTilt = rTiltRaw * gPivot;\nlTiltAct = mix(lFiltered, lTilt, tiltOn);\nrTiltAct = mix(rFiltered, rTilt, tiltOn);\n\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO DE DISTORSIÓN + CONMUTADOR PRE/POST TILT (SUAVIZADO)\n// -----------------------------------------------------------------------------\n\n// ---- Pesos por modo (igual que antes) ----\nmode = smoothedMode;\n\nw0 = max(0, 1 - abs(mode - 0));\nw1 = max(0, 1 - abs(mode - 1));\nw2 = max(0, 1 - abs(mode - 2));\nw3 = max(0, 1 - abs(mode - 3));\nw4 = max(0, 1 - abs(mode - 4));\nw5 = max(0, 1 - abs(mode - 5));\nw6 = max(0, 1 - abs(mode - 6));\nw7 = max(0, 1 - abs(mode - 7));\n\nsumWeights = w0 + w1 + w2 + w3 + w4 + w5 + w6 + w7 + 0.0001;\nw0 /= sumWeights; w1 /= sumWeights; w2 /= sumWeights; w3 /= sumWeights;\nw4 /= sumWeights; w5 /= sumWeights; w6 /= sumWeights; w7 /= sumWeights;\n\n// --- Normalizar y escalar el parámetro DC para asimetría ---\n// Si c_DC es [0..1] en GUI:\ndcNorm = hDc * 2.0 - 1.0;\ndcSkew = tanh(dcNorm * 3.0) * 0.4;\n\n// ========================\n// TONE+Q en PRE (justo antes de la distorsión)\n// Reutilizamos coeficientes LPF (t_a0,t_a1,t_a2,t_b1,t_b2)\n// ========================\n// RUTA A (entrada = lTiltAct/rTiltAct)\npreAL_x1p = fixdenorm(preToneAL_x1);\npreAL_x2p = fixdenorm(preToneAL_x2);\npreAL_y1p = fixdenorm(preToneAL_y1);\npreAL_y2p = fixdenorm(preToneAL_y2);\npreA_L = t_a0 * lTiltAct + t_a1 * preAL_x1p + t_a2 * preAL_x2p - t_b1 * preAL_y1p - t_b2 * preAL_y2p;\npreToneAL_x2 = preAL_x1p; preToneAL_x1 = lTiltAct; preToneAL_y2 = preAL_y1p; preToneAL_y1 = preA_L;\n\npreAR_x1p = fixdenorm(preToneAR_x1);\npreAR_x2p = fixdenorm(preToneAR_x2);\npreAR_y1p = fixdenorm(preToneAR_y1);\npreAR_y2p = fixdenorm(preToneAR_y2);\npreA_R = t_a0 * rTiltAct + t_a1 * preAR_x1p + t_a2 * preAR_x2p - t_b1 * preAR_y1p - t_b2 * preAR_y2p;\npreToneAR_x2 = preAR_x1p; preToneAR_x1 = rTiltAct; preToneAR_y2 = preAR_y1p; preToneAR_y1 = preA_R;\n\n// RUTA B (entrada = preDistInL/R)\npreBL_x1p = fixdenorm(preToneBL_x1);\npreBL_x2p = fixdenorm(preToneBL_x2);\npreBL_y1p = fixdenorm(preToneBL_y1);\npreBL_y2p = fixdenorm(preToneBL_y2);\npreB_L = t_a0 * preDistInL + t_a1 * preBL_x1p + t_a2 * preBL_x2p - t_b1 * preBL_y1p - t_b2 * preBL_y2p;\npreToneBL_x2 = preBL_x1p; preToneBL_x1 = preDistInL; preToneBL_y2 = preBL_y1p; preToneBL_y1 = preB_L;\n\npreBR_x1p = fixdenorm(preToneBR_x1);\npreBR_x2p = fixdenorm(preToneBR_x2);\npreBR_y1p = fixdenorm(preToneBR_y1);\npreBR_y2p = fixdenorm(preToneBR_y2);\npreB_R = t_a0 * preDistInR + t_a1 * preBR_x1p + t_a2 * preBR_x2p - t_b1 * preBR_y1p - t_b2 * preBR_y2p;\npreToneBR_x2 = preBR_x1p; preToneBR_x1 = preDistInR; preToneBR_y2 = preBR_y1p; preToneBR_y1 = preB_R;\n\n// Entradas conmutadas (si PRE y TONE ON → usar preA/preB)\ninA_L = mix(lTiltAct,  preA_L, wTonePre * toneOn);\ninA_R = mix(rTiltAct,  preA_R, wTonePre * toneOn);\ninB_L = mix(preDistInL, preB_L, wTonePre * toneOn);\ninB_R = mix(preDistInR, preB_R, wTonePre * toneOn);\n\n// ========================\n// RUTA A (PRE): Tilt → Dist\n// ========================\nsoftL_A, softR_A = softclip(inA_L, inA_R, drive, dc, ceiling);\nsigmL_A, sigmR_A = sigmoid(inA_L, inA_R, drive, dc, ceiling);\nrectL_A, rectR_A = rectF(inA_L, inA_R, drive, dc, ceiling);\nfuzz1L_A, fuzz1R_A = fuzzExp1(inA_L, inA_R, drive, dc, ceiling);\ntanhL_A, tanhR_A = tangenteHiperbolica(inA_L, inA_R, drive, dc, ceiling);\nrecthL_A, recthR_A = rectH(inA_L, inA_R, drive, dc, ceiling);\natanL_A, atanR_A = arctangent(inA_L, inA_R, drive, dc, ceiling);\nhardL_A, hardR_A = hardClip(inA_L, inA_R, drive, dc, ceiling);\n\ndistL_A = softL_A * w0 + sigmL_A * w1 + rectL_A * w2 + fuzz1L_A * w3 +\n          tanhL_A * w4 + recthL_A * w5 + atanL_A * w6 + hardL_A * w7;\n\ndistR_A = softR_A * w0 + sigmR_A * w1 + rectR_A * w2 + fuzz1R_A * w3 +\n          tanhR_A * w4 + recthR_A * w5 + atanR_A * w6 + hardR_A * w7;\n\npreOutL = dcblock(distL_A);\npreOutR = dcblock(distR_A);\n\n// ========================\n// RUTA B (POST): Dist → Tilt\n// ========================\n// 1) Distorsión sobre la señal SIN tilt (preDistInL/R)\nsoftL_B, softR_B = softclip(inB_L, inB_R, drive, dcSkew, ceiling);\nsigmL_B, sigmR_B = sigmoid(inB_L, inB_R, drive, dcSkew, ceiling);\nrectL_B, rectR_B = rectF(inB_L, inB_R, drive, dcSkew, ceiling);\nfuzz1L_B, fuzz1R_B = fuzzExp1(inB_L, inB_R, drive, dcSkew, ceiling);\ntanhL_B, tanhR_B = tangenteHiperbolica(inB_L, inB_R, drive, dcSkew, ceiling);\nrecthL_B, recthR_B = rectH(inB_L, inB_R, drive, dcSkew, ceiling);\natanL_B, atanR_B = arctangent(inB_L, inB_R, drive, dcSkew, ceiling);\nhardL_B, hardR_B = hardClip(inB_L, inB_R, drive, dcSkew, ceiling);\n\ndistL_B = softL_B * w0 + sigmL_B * w1 + rectL_B * w2 + fuzz1L_B * w3 +\n          tanhL_B * w4 + recthL_B * w5 + atanL_B * w6 + hardL_B * w7;\n\ndistR_B = softR_B * w0 + sigmR_B * w1 + rectR_B * w2 + fuzz1R_B * w3 +\n          tanhR_B * w4 + recthR_B * w5 + atanR_B * w6 + hardR_B * w7;\n\npostInL = dcblock(distL_B);\npostInR = dcblock(distR_B);\n\n// 2) Aplicar el MISMO TILT RBJ a la salida distorsionada (usa histories \"post*\")\n//    (Reutilizamos a0Ls/a1Ls/a2Ls/b1Ls/b2Ls y a0Hs/a1Hs/a2Hs/b1Hs/b2Hs y gPivot)\n\n// --- Low Shelf (ruta post) ---\npostLsL = a0Ls * postInL + a1Ls * postTiltLsL2 + a2Ls * postTiltLsL1 - b1Ls * postTiltLsL4 - b2Ls * postTiltLsL3;\npostTiltLsL1 = postTiltLsL2; postTiltLsL2 = postInL; postTiltLsL3 = postTiltLsL4; postTiltLsL4 = postLsL;\n\npostLsR = a0Ls * postInR + a1Ls * postTiltLsR2 + a2Ls * postTiltLsR1 - b1Ls * postTiltLsR4 - b2Ls * postTiltLsR3;\npostTiltLsR1 = postTiltLsR2; postTiltLsR2 = postInR; postTiltLsR3 = postTiltLsR4; postTiltLsR4 = postLsR;\n\n// --- High Shelf (ruta post) ---\npostTiltRawL = a0Hs * postLsL + a1Hs * postTiltHsL2 + a2Hs * postTiltHsL1 - b1Hs * postTiltHsL4 - b2Hs * postTiltHsL3;\npostTiltHsL1 = postTiltHsL2; postTiltHsL2 = postLsL; postTiltHsL3 = postTiltHsL4; postTiltHsL4 = postTiltRawL;\n\npostTiltRawR = a0Hs * postLsR + a1Hs * postTiltHsR2 + a2Hs * postTiltHsR1 - b1Hs * postTiltHsR4 - b2Hs * postTiltHsR3;\npostTiltHsR1 = postTiltHsR2; postTiltHsR2 = postLsR; postTiltHsR3 = postTiltHsR4; postTiltHsR4 = postTiltRawR;\n\n// Normalización al pivote (misma gPivot)\npostTiltL = postTiltRawL * gPivot;\npostTiltR = postTiltRawR * gPivot;\npostTiltActL = mix(postInL, postTiltL, tiltOn);\npostTiltActR = mix(postInR, postTiltR, tiltOn);\n\n// ========================\n// MORPH SUAVIZADO ENTRE RUTAS\n// ========================\n// processed* es la entrada al resto de la cadena (bitcrusher, deci, etc.)\n//processedL = mix(preOutL, postTiltL, wPost);\n//processedR = mix(preOutR, postTiltR, wPost);\n\ndistMorphL = mix(preOutL, postTiltActL, wPost);\ndistMorphR = mix(preOutR, postTiltActR, wPost);\n\n// Base PRE ya con TONE si está activo (independiente de Dist ON/OFF)\ncleanPreTiltL = inA_L;\ncleanPreTiltR = inA_R;\n\n// Activador global de distorsión\nprocessedL = mix(cleanPreTiltL, distMorphL, wDist);\nprocessedR = mix(cleanPreTiltR, distMorphR, wDist);\n\n// Esto es solo para probar la respuesta del tilt en Plugin Doctor\n//processedL = dcblock(lTilt);\n//processedR = dcblock(rTilt);\n\n// -----------------------------------------------------------------------------\n// BIT CRUSHER Y DOWNSAMPLING OPCIONAL (ANTES DEL DRY/WET)\n// -----------------------------------------------------------------------------\n// Bit Crusher\nbitL, bitR = bitCrusher(processedL, processedR, bits);\nbcL = dcblock(bitL);\nbcR = dcblock(bitR);\n\nwithBitCrusherL = mix(processedL, bcL, bitson);\nwithBitCrusherR = mix(processedR, bcR, bitson);\n\n// Downsampling con phasor y latch\n// Calcular frecuencia del decimador basada en el parámetro\n// Convertir el parámetro (0-99) a factor de decimación entero (1-100)\ndeciFactor = max(1, floor(hDownsample + 1));\ndeciFreq   = samplerate / deciFactor;   // 1 latch por cada N muestras\n\n// Edge de activación (reset de fase al pasar de OFF→ON)\nenableNow  = downsampleOn > 0.5;\nenableEdge = enableNow > dsEnablePrev;   // flanco de subida\ndsEnablePrev = enableNow;\n\n// Phasor manual 0..1 con reset en el flanco de activación\ninc = 1 / deciFactor;                   // equivalente a deciFreq/samplerate, más claro\ndsPhase = enableEdge ? 0 : (dsPhase + inc);\ndsPhase = dsPhase - floor(dsPhase);\n\n// Disparo robusto: en el wrap-around (fase actual < fase anterior) o si N==1\ndsEdgeWrap = dsPhase < dsTrigPrev;      // usa dsTrigPrev como \"fase previa\"\ndsEdge = (enableEdge + dsEdgeWrap + (deciFactor == 1)) > 0.5;\ndsTrigPrev = dsPhase;\n\n// Latch SOLO en el flanco\ndsHeldL = latch(withBitCrusherL, dsEdge);\ndsHeldR = latch(withBitCrusherR, dsEdge);\n\n// Aplicar downsampling\nwetFinalL = mix(withBitCrusherL, dsHeldL, downsampleOn);\nwetFinalR = mix(withBitCrusherR, dsHeldR, downsampleOn);\n\n// -----------------------------------------------------------------------------\n// OUTPUT MAKEUP (SOLO A LA SEÑAL WET)\n// -----------------------------------------------------------------------------\nwetWithMakeupL = (wetFinalL * outputMakeupLinear) + (bypassWhenActiveL * scSm);\nwetWithMakeupR = (wetFinalR * outputMakeupLinear) + (bypassWhenActiveR * scSm);\n\n// ---------- LPF SOLO EN LA RUTA WET + ALLPASS EN LA RUTA DRY ----------\n// Coeficientes (t_a0..t_b2 y ap_*) ya calculados arriba (antes del bloque de distorsión).\n\n// --- LPF sobre la ruta WET ---\ntL_x1p = fixdenorm(toneL_x1);\ntL_x2p = fixdenorm(toneL_x2);\ntL_y1p = fixdenorm(toneL_y1);\ntL_y2p = fixdenorm(toneL_y2);\n\nwetToneL = t_a0 * wetWithMakeupL + t_a1 * tL_x1p + t_a2 * tL_x2p\n         - t_b1 * tL_y1p - t_b2 * tL_y2p;\n\ntoneL_x2 = tL_x1p;\ntoneL_x1 = wetWithMakeupL;\ntoneL_y2 = tL_y1p;\ntoneL_y1 = wetToneL;\n\ntR_x1p = fixdenorm(toneR_x1);\ntR_x2p = fixdenorm(toneR_x2);\ntR_y1p = fixdenorm(toneR_y1);\ntR_y2p = fixdenorm(toneR_y2);\n\nwetToneR = t_a0 * wetWithMakeupR + t_a1 * tR_x1p + t_a2 * tR_x2p\n         - t_b1 * tR_y1p - t_b2 * tR_y2p;\n\ntoneR_x2 = tR_x1p;\ntoneR_x1 = wetWithMakeupR;\ntoneR_y2 = tR_y1p;\ntoneR_y1 = wetToneR;\n\n// Toggle para activar/desactivar el LPF en el WET\n// El LPF en WET solo se aplica cuando TONE está en POST\nwetProcessedL = mix(wetWithMakeupL, wetToneL, toneOn * wTonePost);\nwetProcessedR = mix(wetWithMakeupR, wetToneR, toneOn * wTonePost);\n\n// --- Allpass sobre la ruta DRY para compensar la fase ---\napL_x1p = fixdenorm(toneApL_x1);\napL_x2p = fixdenorm(toneApL_x2);\napL_y1p = fixdenorm(toneApL_y1);\napL_y2p = fixdenorm(toneApL_y2);\n\ndryCompL = ap_b0 * dryL + ap_b1 * apL_x1p + ap_b2 * apL_x2p\n         - ap_a1 * apL_y1p - ap_a2 * apL_y2p;\n\ntoneApL_x2 = apL_x1p;\ntoneApL_x1 = dryL;\ntoneApL_y2 = apL_y1p;\ntoneApL_y1 = dryCompL;\n\napR_x1p = fixdenorm(toneApR_x1);\napR_x2p = fixdenorm(toneApR_x2);\napR_y1p = fixdenorm(toneApR_y1);\napR_y2p = fixdenorm(toneApR_y2);\n\ndryCompR = ap_b0 * dryR + ap_b1 * apR_x1p + ap_b2 * apR_x2p\n         - ap_a1 * apR_y1p - ap_a2 * apR_y2p;\n\ntoneApR_x2 = apR_x1p;\ntoneApR_x1 = dryR;\ntoneApR_y2 = apR_y1p;\ntoneApR_y1 = dryCompR;\n\n// Compensación de fase en DRY siempre que TONE esté activo (PRE o POST)\ndryProcessedL = mix(dryL, dryCompL, toneOn);\ndryProcessedR = mix(dryR, dryCompR, toneOn);\n\n// -----------------------------------------------------------------------------\n// MEZCLA DRY/WET\n// -----------------------------------------------------------------------------\nmixedL = mix(dryProcessedL, wetProcessedL, drywet);\nmixedR = mix(dryProcessedR, wetProcessedR, drywet);\n\n// -----------------------------------------------------------------------------\n// SALIDA FINAL CON BYPASS\n// -----------------------------------------------------------------------------\n\n// Ceiling fijo\nsafeCeiling = dbtoa(-0.1);\n\n// Limitador de seguridad (usa toneOut*)\nsafeL = mix(mixedL, clamp(mixedL, -safeCeiling, safeCeiling), safeOn);\nsafeR = mix(mixedR, clamp(mixedR, -safeCeiling, safeCeiling), safeOn);\n\nout1 = mix(lIn, safeL, bypass);\nout2 = mix(rIn, safeR, bypass);\n\n// Salida 3 vacía para mantener consistencia\nout3 = 0;\n\n// Salidas post Input Trim (para medidores)\nout4 = lTrimmed;  // L post trim\nout5 = rTrimmed;  // R post trim",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-3",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "" ],
									"patching_rect" : [ 33.0, 56.0, 825.0, 776.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 33.0, 846.0, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-3", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-3", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-3", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-3", 2 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 208.0, 429.0, 711.5, 22.0 ],
					"saved_object_attributes" : 					{
						"autoexport" : 0,
						"exportfolder" : "Sequoia:/Users/jcb/JUCEProjects/JCBDistortion/exported-code/"
					}
,
					"text" : "gen~ @title JCBDistortion @autoexport 0"
				}

			}
, 			{
				"box" : 				{
					"attr" : "exportfolder",
					"id" : "obj-43",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 84.0, 29.0, 458.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1141.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1064.5, 367.0, 217.5, 367.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 361.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 687.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-122", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1122.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"midpoints" : [ 361.5, 559.0, 189.5, 559.0 ],
					"order" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"midpoints" : [ 361.5, 559.0, 511.5, 559.0 ],
					"order" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1153.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"midpoints" : [ 511.5, 663.04296875, 369.5, 663.04296875 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 1 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 1 ],
					"midpoints" : [ 390.625, 531.0, 539.5, 531.0 ],
					"order" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"midpoints" : [ 390.625, 527.953125, 428.5, 527.953125 ],
					"order" : 1,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"midpoints" : [ 217.5, 458.0, 236.5, 458.0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"midpoints" : [ 390.625, 461.5, 405.5, 461.5 ],
					"order" : 2,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"midpoints" : [ 217.5, 514.0, 164.5, 514.0 ],
					"order" : 2,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"source" : [ "obj-2", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"source" : [ "obj-2", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1381.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1185.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 838.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 377.5, 399.5, 217.5, 399.5 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1233.5, 367.0, 217.5, 367.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1403.5, 826.2265625, 1176.5, 826.2265625 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1027.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 954.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1038.5, 687.0, 1176.5, 687.0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"midpoints" : [ 189.5, 662.296875, 343.5, 662.296875 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1496.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1218.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 93.5, 108.0, 93.359375, 108.0, 93.359375, 398.8515625, 217.5, 398.8515625 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"midpoints" : [ 361.5, 618.0, 532.5, 618.0 ],
					"order" : 0,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 361.5, 618.5, 210.5, 618.5 ],
					"order" : 1,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1252.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"midpoints" : [ 258.0, 119.97265625, 311.5, 119.97265625 ],
					"source" : [ "obj-46", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1283.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 1141.5, 219.0, 1141.5, 219.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1282.5, 687.0, 1176.5, 687.0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1520.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1059.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1176.5, 637.5, 1176.5, 637.5 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 755.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 740.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 116.5, 398.7890625, 217.5, 398.7890625 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"source" : [ "obj-61", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-64", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 838.5, 87.0, 810.0, 87.0, 810.0, 132.0, 810.14453125, 132.0, 810.14453125, 414.0, 217.5, 414.0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-66", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 511.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-67", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-67", 0 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 602.5, 399.0, 217.5, 399.0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1461.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-70", 0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1547.5, 415.0, 217.5, 415.0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 246.5, 239.714952761627956, 218.5, 239.714952761627956 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 311.5, 238.523546511627956, 218.5, 238.523546511627956 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1090.5, 118.0, 1141.5, 118.0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 152.5, 397.7578125, 217.5, 397.7578125 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 217.5, 239.953234011627956, 218.5, 239.953234011627956 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-75", 0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1423.5, 825.7578125, 1176.5, 825.7578125 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 269.5, 347.5, 910.0, 347.5 ],
					"source" : [ "obj-84", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1506.5, 825.0, 1176.5, 825.0 ],
					"source" : [ "obj-86", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-65", 0 ],
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1537.5, 852.0, 1306.953125, 852.0, 1306.953125, 825.0, 1176.5, 825.0 ],
					"source" : [ "obj-90", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"source" : [ "obj-95", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-96", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-121" : [ "HPF", "HPF", 0 ],
			"obj-122" : [ "LPF", "LPF", 0 ],
			"obj-34" : [ "number[4]", "number[4]", 0 ],
			"obj-44" : [ "number", "number", 0 ],
			"obj-53" : [ "number[5]", "number[5]", 0 ],
			"obj-68" : [ "toggle", "toggle", 0 ],
			"obj-71" : [ "number[1]", "number[1]", 0 ],
			"obj-74" : [ "number[2]", "number[2]", 0 ],
			"obj-85" : [ "TONE", "TONE", 0 ],
			"obj-91" : [ "Q", "Q", 0 ],
			"obj-95" : [ "number[3]", "number[3]", 0 ],
			"parameterbanks" : 			{
				"0" : 				{
					"index" : 0,
					"name" : "",
					"parameters" : [ "-", "-", "-", "-", "-", "-", "-", "-" ]
				}

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
