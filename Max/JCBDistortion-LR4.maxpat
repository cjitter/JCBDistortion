{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 9,
			"minor" : 0,
			"revision" : 7,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 178.0, 87.0, 1690.0, 903.0 ],
		"gridsize" : [ 15.0, 15.0 ],
		"boxes" : [ 			{
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
							"revision" : 7,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 562.0, 127.0, 748.0, 831.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"fontsize" : 21.0,
									"id" : "obj-2",
									"linecount" : 33,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 37.0, 14.0, 660.0, 781.0 ],
									"text" : "// -----------------------------------------------------------------------------\n// PARÁMETROS\n// -----------------------------------------------------------------------------\nParam a_DRYWET(1, min=0, default=1, max=1);\nParam b_DRIVE(1, min=1, default=1, max=50);\nParam c_DC(0, min=0, default=0, max=1);         // DC offset - añade armónicos pares (asimetría)\nParam d_MODE(1, min=0, default=0, max=7);       // Continuo 0-7 (8 algoritmos)\nParam e_CEILING(0, min=-20, default=0, max=6);\nParam f_BYPASS(0, min=0, default=0, max=1);\nParam g_BITS(16, min=3, default=16, max=16);\nParam h_BITSON(0, min=0, default=0, max=1);\nParam i_TILT(0, min=-6, default=0, max=6);\n\n// Parámetros de filtros HPF/LPF\nParam j_HPF(250, min=20, default=250, max=1000);      // XOver low frequency (Hz)\nParam k_LPF(5000, min=1000, default=5000, max=20000); // XOver high frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable\n\n// Parámetros existentes\nParam k_INPUT(0, min=-12, default=0, max=12);   // Input trim gain\nParam l_OUTPUT(0, min=-12, default=0, max=12);  // Output makeup gain\nParam m_DOWNSAMPLE(0, min=0, default=0, max=99); // Factor de downsampling (0 = sin efecto)\nParam n_DOWNSAMPLEON(0, min=0, default=0, max=1); // Activar downsampling\n\nParam o_BAND(1, min=0, default=1, max=2); // 0=low,1=mid,2=high"
								}

							}
 ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 51.0, 419.0, 60.0, 22.0 ],
					"text" : "p Params"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "preset", "int", "preset", "int", "" ],
					"patching_rect" : [ 279.5, 60.0, 100.0, 40.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-43", "attrui", "attr", "exportfolder", 4, "obj-43", "attrui", "Sequoia:/Users/jcb/JUCEProjects/JCBDistortion/exported-code/", 5, "obj-44", "number", "float", 0.25, 5, "obj-15", "toggle", "int", 1, 5, "obj-87", "number", "float", 3.0, 5, "obj-93", "number", "float", 0.0, 5, "obj-95", "number", "float", 0.5, 5, "obj-26", "number", "float", 0.0, 5, "obj-52", "toggle", "int", 0, 5, "obj-27", "toggle", "int", 0, 5, "obj-53", "number", "float", 16.0, 5, "obj-61", "number", "float", 0.0, 5, "obj-48", "number", "float", 0.0, 5, "obj-31", "number", "float", 0.0, 5, "obj-37", "number", "float", 0.0, 5, "obj-73", "multislider", "list", 0.0, 5, "obj-9", "toggle", "int", 0, 5, "obj-13", "number", "float", 0.0, 5, "obj-62", "toggle", "int", 1, 5, "obj-71", "number", "float", 256.358489990234375, 5, "obj-74", "number", "float", 5286.7919921875, 5, "obj-121", "live.dial", "float", 256.358489990234375, 5, "obj-122", "live.dial", "float", 5286.7919921875, 5, "obj-77", "toggle", "int", 0, 5, "obj-34", "number", "int", 1 ]
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
					"patching_rect" : [ 1526.0, 15.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1589.0, 15.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1557.0, 15.0, 29.5, 22.0 ],
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
					"parameter_enable" : 0,
					"patching_rect" : [ 1526.0, 60.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1526.0, 98.0, 72.0, 22.0 ],
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
					"patching_rect" : [ 255.0, 148.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 255.0, 179.0, 65.0, 22.0 ],
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
					"patching_rect" : [ 320.0, 119.0, 21.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 226.0, 118.0, 88.0, 22.0 ],
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
					"patching_rect" : [ 227.0, 234.0, 121.0, 22.0 ],
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
					"patching_rect" : [ 1505.0, 455.0, 75.0, 74.0 ],
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
					"patching_rect" : [ 1261.0, 457.0, 75.0, 74.0 ],
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
					"patching_rect" : [ 1505.0, 553.0, 68.0, 22.0 ],
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
					"patching_rect" : [ 1261.0, 553.0, 64.0, 22.0 ],
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
					"patching_rect" : [ 1398.0, 692.0, 51.0, 22.0 ],
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
					"patching_rect" : [ 1399.0, 458.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1399.0, 488.0, 51.0, 22.0 ],
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
					"patching_rect" : [ 1505.0, 586.0, 60.0, 22.0 ],
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
					"patching_rect" : [ 1261.0, 586.0, 59.0, 22.0 ],
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
					"patching_rect" : [ 918.0, 20.0, 103.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 917.0, 48.0, 129.0, 22.0 ],
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
					"patching_rect" : [ 748.0, 19.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 748.0, 48.0, 143.0, 22.0 ],
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
					"patching_rect" : [ 39.0, 244.0, 49.0, 22.0 ],
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
					"patching_rect" : [ 1150.0, 129.0, 158.0, 35.0 ],
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
					"patching_rect" : [ 918.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 745.0, 505.0, 82.0, 22.0 ],
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
					"patching_rect" : [ 745.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1292.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1261.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1227.0, 28.0, 29.5, 22.0 ],
					"text" : "5"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-37",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1423.0, 69.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1423.0, 98.0, 84.0, 22.0 ],
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
					"patching_rect" : [ 531.0, 89.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 531.0, 134.0, 74.0, 22.0 ],
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
					"patching_rect" : [ 1068.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1150.0, 174.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 745.0, 560.0, 276.0, 219.0 ],
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
					"patching_rect" : [ 764.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 764.0, 135.0, 58.0, 22.0 ],
					"text" : "i_TILT $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-53",
					"maxclass" : "flonum",
					"maximum" : 16.0,
					"minimum" : 3.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 963.0, 161.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 963.0, 208.0, 65.0, 22.0 ],
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
					"patching_rect" : [ 1036.0, 161.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1036.0, 208.0, 83.0, 22.0 ],
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
					"patching_rect" : [ 414.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 245.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1194.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1162.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1131.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1099.0, 28.0, 29.5, 22.0 ],
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
					"patching_rect" : [ 1326.0, 68.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1326.0, 98.0, 82.0, 22.0 ],
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
					"patching_rect" : [ 832.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 135.0, 87.0, 22.0 ],
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
					"patching_rect" : [ 1150.0, 207.0, 75.0, 22.0 ],
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
					"patching_rect" : [ 437.0, 665.0, 139.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 520.0, 566.0, 47.0, 22.0 ],
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
					"patching_rect" : [ 520.0, 616.0, 40.0, 22.0 ],
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
					"patching_rect" : [ 125.0, 52.0, 68.0, 22.0 ],
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
					"patching_rect" : [ 437.0, 134.0, 90.0, 22.0 ],
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
					"parameter_enable" : 0,
					"patching_rect" : [ 437.0, 88.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 696.0, 88.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 611.0, 88.0, 50.0, 22.0 ]
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
					"patching_rect" : [ 370.0, 478.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 198.0, 572.0, 47.0, 22.0 ],
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
					"patching_rect" : [ 370.0, 572.0, 50.0, 22.0 ],
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
					"patching_rect" : [ 696.0, 135.0, 55.0, 22.0 ],
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
					"patching_rect" : [ 611.0, 135.0, 75.0, 22.0 ],
					"text" : "b_DRIVE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 352.0, 673.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 198.0, 616.0, 40.0, 22.0 ],
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
					"patching_rect" : [ 173.0, 665.0, 139.0, 114.0 ]
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
							"revision" : 7,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 849.0, 87.0, 964.0, 904.0 ],
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
									"patching_rect" : [ 839.0, 853.0, 35.0, 22.0 ],
									"text" : "out 5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 638.0, 846.0, 35.0, 22.0 ],
									"text" : "out 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 235.0, 853.0, 35.0, 22.0 ],
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
									"code" : "// =============================================================================\n// MULTI-ALGORITHM DISTORTION WITH SIMPLE WORKING FILTERS\n// =============================================================================\n// Plugin de distorsión con múltiples algoritmos y morphing continuo\n// Filtros HPF/LPF simples que funcionan correctamente\n// Dry/Wet mezcla señal original (pre-trim) con señal completamente procesada\n// =============================================================================\n\n// -----------------------------------------------------------------------------\n// FUNCIONES DE DISTORSIÓN (en orden de modo)\n// -----------------------------------------------------------------------------\n\n// MODO 0 - Soft Clipping - Saturación suave con función cúbica\nsoftclip(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría (armónicos pares)\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    // Aplicar drive y normalizar\n    lNorm = (lWithDC * dr) / cell;\n    rNorm = (rWithDC * dr) / cell;\n    \n    lCubic = lNorm - (lNorm * lNorm * lNorm) / 3;\n    rCubic = rNorm - (rNorm * rNorm * rNorm) / 3;\n    \n    lLimited = sign(lNorm) * (2.0 / 3.0);\n    rLimited = sign(rNorm) * (2.0 / 3.0);\n    \n    lOut = (abs(lNorm) <= 1) ? lCubic : lLimited;\n    rOut = (abs(rNorm) <= 1) ? rCubic : rLimited;\n    \n    return lOut * cell, rOut * cell;\n}\n\n// MODO 1 - Sigmoid - Curva en S para saturación suave\nsigmoid(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    factor = (-1) * dr;\n    l = (2 * (1 / (1 + exp(factor * lWithDC)))) - 1;\n    r = (2 * (1 / (1 + exp(factor * rWithDC)))) - 1;\n    \n    // Aplicar ceiling para limitar la salida\n    lOut = clip(l * cell, -cell, cell);\n    rOut = clip(r * cell, -cell, cell);\n    \n    return lOut, rOut;\n}\n\n// MODO 2 - Rectificador Full Wave - Bipolar con compensación de ganancia\nrectF(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para cambiar el punto de rectificación\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    l = sign(lWithDC) * abs(lWithDC * dr) * 0.707;\n    r = sign(rWithDC) * abs(rWithDC * dr) * 0.707;\n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 3 - Fuzz Exponencial 1 - Distorsión tipo fuzz con curva exponencial\nfuzzExp1(inl, inr, dr, dc, cell) {\n    // Añadir DC offset ANTES del procesamiento para generar asimetría\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    signl = sign(lWithDC);\n    signr = sign(rWithDC);\n    \n    lScaled = abs(lWithDC * dr);\n    rScaled = abs(rWithDC * dr);\n    \n    l = signl * (1 - exp(-lScaled));\n    r = signr * (1 - exp(-rScaled));\n    \n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 4 - Tangente Hiperbólica - Distorsión suave tipo saturación de cinta\ntangenteHiperbolica(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    l = clip(lWithDC * dr, -cell, cell);\n    r = clip(rWithDC * dr, -cell, cell);\n    lOut = (tanh(l)) / (tanh(dr));\n    rOut = (tanh(r)) / (tanh(dr));\n    return lOut, rOut;\n}\n\n// MODO 5 - Rectificador Half Wave - Solo valores positivos\nrectH(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para cambiar el punto de rectificación\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    lPositive = max(lWithDC, 0);\n    rPositive = max(rWithDC, 0);\n    l = clip((lPositive * dr) * 0.5, -cell, cell);\n    r = clip((rPositive * dr) * 0.5, -cell, cell);\n    return l, r;\n}\n\n// MODO 6 - Arctangente puro - Distorsión suave con compresión natural\narctangent(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    lScaled = lWithDC * dr * 2;\n    rScaled = rWithDC * dr * 2;\n    \n    l = (2 / pi) * atan(lScaled);\n    r = (2 / pi) * atan(rScaled);\n    \n    lOut = l * cell;\n    rOut = r * cell;\n    \n    return lOut, rOut;\n}\n\n// MODO 7 - Hard Clip - Recorte abrupto de la señal\nhardClip(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.01);\n    rWithDC = inr + (dc * 0.01);\n    \n    // Aplicar drive y calcular threshold\n    lDriven = lWithDC * dr;\n    rDriven = rWithDC * dr;\n    \n    // Clipear a ±cell\n    l = (lDriven > cell) ? cell : ((lDriven < -cell) ? -cell : lDriven);\n    r = (rDriven > cell) ? cell : ((rDriven < -cell) ? -cell : rDriven);\n    \n    return l, r;\n}\n\n// Bit Crusher - Reduce la resolución de bits\nbitCrusher(inl, inr, bits) {\n    steps = pow(2, bits) - 1;\n    invSteps = 1 / steps;\n    l = ceil(inl * steps) * invSteps;\n    r = ceil(inr * steps) * invSteps;\n    return l, r;\n}\n\n// -----------------------------------------------------------------------------\n// PARÁMETROS\n// -----------------------------------------------------------------------------\nParam a_DRYWET(1, min=0, default=1, max=1);\nParam b_DRIVE(1, min=1, default=1, max=50);\nParam c_DC(0, min=0, default=0, max=1);         // DC offset - añade armónicos pares (asimetría)\nParam d_MODE(1, min=0, default=0, max=7);       // Continuo 0-7 (8 algoritmos)\nParam e_CEILING(0, min=-20, default=0, max=6);\nParam f_BYPASS(0, min=0, default=0, max=1);\nParam g_BITS(16, min=3, default=16, max=16);\nParam h_BITSON(0, min=0, default=0, max=1);\nParam i_TILT(0, min=-6, default=0, max=6);\n\n// Parámetros de filtros HPF/LPF\nParam j_HPF(250, min=20, default=250, max=1000);      // XOver low frequency (Hz)\nParam k_LPF(5000, min=1000, default=5000, max=20000); // XOver high frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable\n\n// Parámetros existentes\nParam k_INPUT(0, min=-12, default=0, max=12);   // Input trim gain\nParam l_OUTPUT(0, min=-12, default=0, max=12);  // Output makeup gain\nParam m_DOWNSAMPLE(0, min=0, default=0, max=99); // Factor de downsampling (0 = sin efecto)\nParam n_DOWNSAMPLEON(0, min=0, default=0, max=1); // Activar downsampling\n\nParam o_BAND(1, min=0, default=1, max=2); // 0=low,1=mid,2=high\n// -----------------------------------------------------------------------------\n// HISTORIALES PARA SMOOTHING\n\nHistory L_l1_x2(0), L_l1_y1(0), L_l1_y2(0), L_l2_x2(0);\nHistory L_l2_y1(0), L_l2_y2(0), L_h1_x2(0), L_h1_y1(0);\nHistory L_h1_y2(0), L_h2_x2(0), L_h2_y1(0), L_h2_y2(0);\nHistory L_m1_x2(0), L_m1_y1(0), L_m1_y2(0), L_m2_x2(0);\nHistory L_m2_y1(0), L_m2_y2(0), L_u1_x2(0), L_u1_y1(0);\nHistory L_u1_y2(0), L_u2_x2(0), L_u2_y1(0), L_u2_y2(0);\nHistory L_ap_low_lp1_x2(0), L_ap_low_lp1_y1(0), L_ap_low_lp1_y2(0), L_ap_low_lp2_x2(0);\nHistory L_ap_low_lp2_y1(0), L_ap_low_lp2_y2(0), L_ap_low_hp1_x2(0), L_ap_low_hp1_y1(0);\nHistory L_ap_low_hp1_y2(0), L_ap_low_hp2_x2(0), L_ap_low_hp2_y1(0), L_ap_low_hp2_y2(0);\nHistory L_ap1_lp1_x2(0), L_ap1_lp1_y1(0), L_ap1_lp1_y2(0), L_ap1_lp2_x2(0);\nHistory L_ap1_lp2_y1(0), L_ap1_lp2_y2(0), L_ap1_hp1_x2(0), L_ap1_hp1_y1(0);\nHistory L_ap1_hp1_y2(0), L_ap1_hp2_x2(0), L_ap1_hp2_y1(0), L_ap1_hp2_y2(0);\nHistory L_ap2_lp1_x2(0), L_ap2_lp1_y1(0), L_ap2_lp1_y2(0), L_ap2_lp2_x2(0);\nHistory L_ap2_lp2_y1(0), L_ap2_lp2_y2(0), L_ap2_hp1_x2(0), L_ap2_hp1_y1(0);\nHistory L_ap2_hp1_y2(0), L_ap2_hp2_x2(0), L_ap2_hp2_y1(0), L_ap2_hp2_y2(0);\nHistory R_l1_x2(0), R_l1_y1(0), R_l1_y2(0), R_l2_x2(0);\nHistory R_l2_y1(0), R_l2_y2(0), R_h1_x2(0), R_h1_y1(0);\nHistory R_h1_y2(0), R_h2_x2(0), R_h2_y1(0), R_h2_y2(0);\nHistory R_m1_x2(0), R_m1_y1(0), R_m1_y2(0), R_m2_x2(0);\nHistory R_m2_y1(0), R_m2_y2(0), R_u1_x2(0), R_u1_y1(0);\nHistory R_u1_y2(0), R_u2_x2(0), R_u2_y1(0), R_u2_y2(0);\nHistory R_ap_low_lp1_x2(0), R_ap_low_lp1_y1(0), R_ap_low_lp1_y2(0), R_ap_low_lp2_x2(0);\nHistory R_ap_low_lp2_y1(0), R_ap_low_lp2_y2(0), R_ap_low_hp1_x2(0), R_ap_low_hp1_y1(0);\nHistory R_ap_low_hp1_y2(0), R_ap_low_hp2_x2(0), R_ap_low_hp2_y1(0), R_ap_low_hp2_y2(0);\nHistory R_ap1_lp1_x2(0), R_ap1_lp1_y1(0), R_ap1_lp1_y2(0), R_ap1_lp2_x2(0);\nHistory R_ap1_lp2_y1(0), R_ap1_lp2_y2(0), R_ap1_hp1_x2(0), R_ap1_hp1_y1(0);\nHistory R_ap1_hp1_y2(0), R_ap1_hp2_x2(0), R_ap1_hp2_y1(0), R_ap1_hp2_y2(0);\nHistory R_ap2_lp1_x2(0), R_ap2_lp1_y1(0), R_ap2_lp1_y2(0), R_ap2_lp2_x2(0);\nHistory R_ap2_lp2_y1(0), R_ap2_lp2_y2(0), R_ap2_hp1_x2(0), R_ap2_hp1_y1(0);\nHistory R_ap2_hp1_y2(0), R_ap2_hp2_x2(0), R_ap2_hp2_y1(0), R_ap2_hp2_y2(0);\nHistory l1_x1(0), l1_x2(0), l1_y1(0), l1_y2(0);\nHistory l2_x1(0), l2_x2(0), l2_y1(0), l2_y2(0);\nHistory h1_x1(0), h1_x2(0), h1_y1(0), h1_y2(0);\nHistory h2_x1(0), h2_x2(0), h2_y1(0), h2_y2(0);\nHistory m1_x1(0), m1_x2(0), m1_y1(0), m1_y2(0);\nHistory m2_x1(0), m2_x2(0), m2_y1(0), m2_y2(0);\nHistory u1_x1(0), u1_x2(0), u1_y1(0), u1_y2(0);\nHistory u2_x1(0), u2_x2(0), u2_y1(0), u2_y2(0);\nHistory ap_low_lp1_x1(0), ap_low_lp1_x2(0), ap_low_lp1_y1(0), ap_low_lp1_y2(0);\nHistory ap_low_lp2_x1(0), ap_low_lp2_x2(0), ap_low_lp2_y1(0), ap_low_lp2_y2(0);\nHistory ap_low_hp1_x1(0), ap_low_hp1_x2(0), ap_low_hp1_y1(0), ap_low_hp1_y2(0);\nHistory ap_low_hp2_x1(0), ap_low_hp2_x2(0), ap_low_hp2_y1(0), ap_low_hp2_y2(0);\nHistory ap1_lp1_x1(0), ap1_lp1_x2(0), ap1_lp1_y1(0), ap1_lp1_y2(0);\nHistory ap1_lp2_x1(0), ap1_lp2_x2(0), ap1_lp2_y1(0), ap1_lp2_y2(0);\nHistory ap1_hp1_x1(0), ap1_hp1_x2(0), ap1_hp1_y1(0), ap1_hp1_y2(0);\nHistory ap1_hp2_x1(0), ap1_hp2_x2(0), ap1_hp2_y1(0), ap1_hp2_y2(0);\nHistory ap2_lp1_x1(0), ap2_lp1_x2(0), ap2_lp1_y1(0), ap2_lp1_y2(0);\nHistory ap2_lp2_x1(0), ap2_lp2_x2(0), ap2_lp2_y1(0), ap2_lp2_y2(0);\nHistory ap2_hp1_x1(0), ap2_hp1_x2(0), ap2_hp1_y1(0), ap2_hp1_y2(0);\nHistory ap2_hp2_x1(0), ap2_hp2_x2(0), ap2_hp2_y1(0), ap2_hp2_y2(0);\nHistory hBand(1);\n// -----------------------------------------------------------------------------\n// Para suavizar cambios de modo\n// Para suavizar factor de downsampling\n// Para suavizar activación de downsampling\n// Para suavizar bypass y evitar clicks\n\n// Historiales para filtros de 1 polo (más simples)\n// Historiales para smoothing de filtros\n// Historiales para el downsampler con phasor\n// Historiales para filtros Tilt\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO PRINCIPAL\n// -----------------------------------------------------------------------------\nHistory hDrive(0);\nHistory hDc(0);\nHistory hDrywet(0);\nHistory hBits(0);\nHistory hBitson(0);\nHistory hTilt(0);\nHistory hInput(0);\nHistory hOutput(0);\nHistory hMode(0);\n\nHistory hDownsample(0);\nHistory hDownsampleOn(0);\nHistory hBypass(0);\nHistory hpfL_z1(0);\nHistory hpfR_z1(0);\nHistory lpfL_z1(0);\nHistory lpfR_z1(0);\nHistory hpfFreqHistory(0);\nHistory lpfFreqHistory(0);\nHistory scEnableHistory(0);\nHistory dsPhasor(0);\n\nHistory dsPhase(0);\nHistory dsTrigPrev(0);\nHistory dsEnablePrev(0);\n\n//History tiltL1(0), tiltL2(0), tiltL3(0), tiltL4(0);\n//History tiltR1(0), tiltR2(0), tiltR3(0), tiltR4(0);\nHistory tiltLsL1(0), tiltLsL2(0), tiltLsL3(0), tiltLsL4(0);\nHistory tiltLsR1(0), tiltLsR2(0), tiltLsR3(0), tiltLsR4(0);\nHistory tiltHsL1(0), tiltHsL2(0), tiltHsL3(0), tiltHsL4(0);\nHistory tiltHsR1(0), tiltHsR2(0), tiltHsR3(0), tiltHsR4(0);\n\nHistory L_l1_x1(0);\nHistory R_l1_x1(0);\nHistory L_l2_x1(0);\nHistory R_l2_x1(0);\nHistory L_h1_x1(0);\nHistory R_h1_x1(0);\nHistory L_h2_x1(0);\nHistory R_h2_x1(0);\nHistory L_m1_x1(0);\nHistory R_m1_x1(0);\nHistory L_m2_x1(0);\nHistory R_m2_x1(0);\nHistory L_u1_x1(0);\nHistory R_u1_x1(0);\nHistory L_u2_x1(0);\nHistory R_u2_x1(0);\nHistory L_ap_low_lp1_x1(0);\nHistory R_ap_low_lp1_x1(0);\nHistory L_ap_low_lp2_x1(0);\nHistory R_ap_low_lp2_x1(0);\nHistory L_ap_low_hp1_x1(0);\nHistory R_ap_low_hp1_x1(0);\nHistory L_ap_low_hp2_x1(0);\nHistory R_ap_low_hp2_x1(0);\nHistory L_ap1_lp1_x1(0);\nHistory R_ap1_lp1_x1(0);\nHistory L_ap1_lp2_x1(0);\nHistory R_ap1_lp2_x1(0);\nHistory L_ap1_hp1_x1(0);\nHistory R_ap1_hp1_x1(0);\nHistory L_ap1_hp2_x1(0);\nHistory R_ap1_hp2_x1(0);\nHistory L_ap2_lp1_x1(0);\nHistory R_ap2_lp1_x1(0);\nHistory L_ap2_lp2_x1(0);\nHistory R_ap2_lp2_x1(0);\nHistory L_ap2_hp1_x1(0);\nHistory R_ap2_hp1_x1(0);\nHistory L_ap2_hp2_x1(0);\nHistory R_ap2_hp2_x1(0);\n// Entrada\nlIn = in1;\nrIn = in2;\n\n// Smoothing de parámetros\nsmoothFactor = 0.999;\nhDrive = hDrive * smoothFactor + b_DRIVE * (1 - smoothFactor);\ndrive = hDrive;\nhDc = hDc * smoothFactor + c_DC * (1 - smoothFactor);\ndc = hDc;\nhDrywet = hDrywet * smoothFactor + a_DRYWET * (1 - smoothFactor);\ndrywet = hDrywet;\nhBits = hBits * smoothFactor + g_BITS * (1 - smoothFactor);\nbits = hBits;\nhBitson = hBitson * smoothFactor + h_BITSON * (1 - smoothFactor);\nbitson = hBitson;\nhTilt = hTilt * smoothFactor + i_TILT * (1 - smoothFactor);\ntiltDb = hTilt;\nhInput = hInput * smoothFactor + k_INPUT * (1 - smoothFactor);\ninputTrimDb = hInput;\nhOutput = hOutput * smoothFactor + l_OUTPUT * (1 - smoothFactor);\noutputMakeupDb = hOutput;\n\nhBand = hBand * smoothFactor + o_BAND * (1 - smoothFactor);\nsmoothedBand = hBand;\n// Suavizado especial para MODE con factor más agresivo para evitar clicks\nmodeSmoothFactor = 0.99;  // Más rápido que otros parámetros pero aún suave\nhMode = hMode * modeSmoothFactor + d_MODE * (1 - modeSmoothFactor);\nsmoothedMode = hMode;\n\n// Suavizado del downsampling\nhDownsample = hDownsample * smoothFactor + m_DOWNSAMPLE * (1 - smoothFactor);\nonSmooth = 0.9; // respuesta rápida (~10% por muestra)\nhDownsampleOn = hDownsampleOn * onSmooth + n_DOWNSAMPLEON * (1 - onSmooth);\ndownsampleOn = hDownsampleOn;\n\n// Suavizado del bypass\nhBypass = hBypass * smoothFactor + (1 - f_BYPASS) * (1 - smoothFactor);\nbypass = hBypass;\n\n// Suavizado de parámetros de filtros\nsmoothHpfFreq = (hpfFreqHistory * smoothFactor) + (j_HPF * (1 - smoothFactor));\nhpfFreqHistory = fixdenorm(smoothHpfFreq);\n\nsmoothLpfFreq = (lpfFreqHistory * smoothFactor) + (k_LPF * (1 - smoothFactor));\nlpfFreqHistory = fixdenorm(smoothLpfFreq);\n\nsmoothScEnable = (scEnableHistory * smoothFactor) + (l_SC * (1 - smoothFactor));\nscEnableHistory = fixdenorm(smoothScEnable);\n\n// -----------------------------------------------------------------------------\n// -----------------------------------------------------------------------------\n// CONVERSIONES A LINEAL PARA TRIMS Y CEILING\n// -----------------------------------------------------------------------------\nceiling = dbtoa(e_CEILING);\ninputTrimLinear = dbtoa(inputTrimDb);\noutputMakeupLinear = dbtoa(outputMakeupDb);\n\n// -----------------------------------------------------------------------------\n// INPUT TRIM (define lTrimmed/rTrimmed antes del crossover)\n// -----------------------------------------------------------------------------\nlTrimmed = lIn * inputTrimLinear;\nrTrimmed = rIn * inputTrimLinear;\n// REEMPLAZO: Crossover LR4 estéreo con selector de banda + Dry allpass compensado\n// -----------------------------------------------------------------------------\nscSm = smoothScEnable; // enable suavizado del crossover\n\n// === L_bindings ===\nL_loF = smoothHpfFreq;\nL_hiF = smoothLpfFreq;\n// L_Crossover L_LR4 L_de 3 L_bandas L_con compensación L_de L_fase L_correcta\n// out1: L_Low (20-250Hz)\n// out2: L_Mid (250-5kHz)\n// out3: L_High (5k-20kHz)\n// out4: L_Suma L_de L_las 3 L_bandas (L_debe L_hacer L_null L_test L_con L_entrada)\n\n// ===== L_DECLARACIONES =====\n// L_Estados L_para L_los 8 L_biquads L_del L_crossover L_principal\n// L_Low L_stage 1\n// L_Low L_stage 2\n// L_Rest L_HP L_stage 1\n// L_Rest L_HP L_stage 2\n// L_Mid L_LP L_stage 1\n// L_Mid L_LP L_stage 2\n// L_High L_HP L_stage 1\n// L_High L_HP L_stage 2\n\n// L_Estados L_para L_all-L_pass L_de compensación L_en L_la L_banda L_LOW\n// ===== L_PROCESO =====\nL_x = lTrimmed;\n\n// L_Proteger L_frecuencias\nL_sr = samplerate;\nL_loF = max(10, min(L_loF, 0.45 * L_sr));\nL_hiFr = max(10, min(L_hiF, 0.45 * L_sr));\nL_hiF = max(L_hiFr, L_loF + 1);\n\n// L_Constantes\nTWOPI = 6.283185307179586;\nL_QBW = 0.7071067811865476; // sqrt(2)/2 L_para L_Butterworth\n\n// === L_Coeficientes L_Butterworth @ L_loF ===\nL_w0_lo = TWOPI * L_loF / L_sr;\nL_cos_lo = cos(L_w0_lo);\nL_sin_lo = sin(L_w0_lo);\nL_alpha_lo = L_sin_lo / (2 * L_QBW);\nL_a0_lo = 1 + L_alpha_lo;\nL_a1_lo = -2 * L_cos_lo;\nL_a2_lo = 1 - L_alpha_lo;\n\n// L_LP @ L_loF (L_normalizado)\nL_lp_b0_l = ((1 - L_cos_lo) * 0.5) / L_a0_lo;\nL_lp_b1_l = (1 - L_cos_lo) / L_a0_lo;\nL_lp_b2_l = L_lp_b0_l;\nL_lp_a1_l = L_a1_lo / L_a0_lo;\nL_lp_a2_l = L_a2_lo / L_a0_lo;\n\n// L_HP @ L_loF (L_normalizado)\nL_hp_b0_l = ((1 + L_cos_lo) * 0.5) / L_a0_lo;\nL_hp_b1_l = -(1 + L_cos_lo) / L_a0_lo;\nL_hp_b2_l = L_hp_b0_l;\nL_hp_a1_l = L_lp_a1_l;\nL_hp_a2_l = L_lp_a2_l;\n\n// === L_Coeficientes L_Butterworth @ L_hiF ===\nL_w0_hi = TWOPI * L_hiF / L_sr;\nL_cos_hi = cos(L_w0_hi);\nL_sin_hi = sin(L_w0_hi);\nL_alpha_hi = L_sin_hi / (2 * L_QBW);\nL_a0_hi = 1 + L_alpha_hi;\nL_a1_hi = -2 * L_cos_hi;\nL_a2_hi = 1 - L_alpha_hi;\n\n// L_LP @ L_hiF (L_normalizado)\nL_lp_b0_h = ((1 - L_cos_hi) * 0.5) / L_a0_hi;\nL_lp_b1_h = (1 - L_cos_hi) / L_a0_hi;\nL_lp_b2_h = L_lp_b0_h;\nL_lp_a1_h = L_a1_hi / L_a0_hi;\nL_lp_a2_h = L_a2_hi / L_a0_hi;\n\n// L_HP @ L_hiF (L_normalizado)\nL_hp_b0_h = ((1 + L_cos_hi) * 0.5) / L_a0_hi;\nL_hp_b1_h = -(1 + L_cos_hi) / L_a0_hi;\nL_hp_b2_h = L_hp_b0_h;\nL_hp_a1_h = L_lp_a1_h;\nL_hp_a2_h = L_lp_a2_h;\n\n// ===== L_PRIMER L_CORTE @ L_loF: L_low (L_LP) L_y L_rest (L_HP) =====\n\n// L_LP L_Stage 1 L_para L_LOW\nL_l1_x1p = L_l1_x1; L_l1_x2p = L_l1_x2; L_l1_y1p = L_l1_y1; L_l1_y2p = L_l1_y2;\nL_low_s1 = L_lp_b0_l*L_x + L_lp_b1_l*L_l1_x1p + L_lp_b2_l*L_l1_x2p - L_lp_a1_l*L_l1_y1p - L_lp_a2_l*L_l1_y2p;\nL_l1_x2 = L_l1_x1p; L_l1_x1 = L_x; L_l1_y2 = L_l1_y1p; L_l1_y1 = L_low_s1;\n\n// L_LP L_Stage 2 L_para L_LOW\nL_l2_x1p = L_l2_x1; L_l2_x2p = L_l2_x2; L_l2_y1p = L_l2_y1; L_l2_y2p = L_l2_y2;\nL_low_raw = L_lp_b0_l*L_low_s1 + L_lp_b1_l*L_l2_x1p + L_lp_b2_l*L_l2_x2p - L_lp_a1_l*L_l2_y1p - L_lp_a2_l*L_l2_y2p;\nL_l2_x2 = L_l2_x1p; L_l2_x1 = L_low_s1; L_l2_y2 = L_l2_y1p; L_l2_y1 = L_low_raw;\n\n// L_HP L_Stage 1 L_para L_REST\nL_h1_x1p = L_h1_x1; L_h1_x2p = L_h1_x2; L_h1_y1p = L_h1_y1; L_h1_y2p = L_h1_y2;\nL_rest_s1 = L_hp_b0_l*L_x + L_hp_b1_l*L_h1_x1p + L_hp_b2_l*L_h1_x2p - L_hp_a1_l*L_h1_y1p - L_hp_a2_l*L_h1_y2p;\nL_h1_x2 = L_h1_x1p; L_h1_x1 = L_x; L_h1_y2 = L_h1_y1p; L_h1_y1 = L_rest_s1;\n\n// L_HP L_Stage 2 L_para L_REST\nL_h2_x1p = L_h2_x1; L_h2_x2p = L_h2_x2; L_h2_y1p = L_h2_y1; L_h2_y2p = L_h2_y2;\nL_rest = L_hp_b0_l*L_rest_s1 + L_hp_b1_l*L_h2_x1p + L_hp_b2_l*L_h2_x2p - L_hp_a1_l*L_h2_y1p - L_hp_a2_l*L_h2_y2p;\nL_h2_x2 = L_h2_x1p; L_h2_x1 = L_rest_s1; L_h2_y2 = L_h2_y1p; L_h2_y1 = L_rest;\n\n// ===== COMPENSACIÓN L_ALL-L_PASS L_para L_LOW =====\n// L_Aplicamos L_un L_all-L_pass L_LP+L_HP @ L_hiF L_a L_la señal L_LOW L_para L_igualar L_el L_delay\n\n// L_All-L_pass L_LP L_stage 1 L_sobre L_low_raw\nL_ap_low_lp1_x1p = L_ap_low_lp1_x1; L_ap_low_lp1_x2p = L_ap_low_lp1_x2;\nL_ap_low_lp1_y1p = L_ap_low_lp1_y1; L_ap_low_lp1_y2p = L_ap_low_lp1_y2;\nL_ap_low_lp_s1 = L_lp_b0_h*L_low_raw + L_lp_b1_h*L_ap_low_lp1_x1p + L_lp_b2_h*L_ap_low_lp1_x2p\n               - L_lp_a1_h*L_ap_low_lp1_y1p - L_lp_a2_h*L_ap_low_lp1_y2p;\nL_ap_low_lp1_x2 = L_ap_low_lp1_x1p; L_ap_low_lp1_x1 = L_low_raw;\nL_ap_low_lp1_y2 = L_ap_low_lp1_y1p; L_ap_low_lp1_y1 = L_ap_low_lp_s1;\n\n// L_All-L_pass L_LP L_stage 2\nL_ap_low_lp2_x1p = L_ap_low_lp2_x1; L_ap_low_lp2_x2p = L_ap_low_lp2_x2;\nL_ap_low_lp2_y1p = L_ap_low_lp2_y1; L_ap_low_lp2_y2p = L_ap_low_lp2_y2;\nL_ap_low_lp = L_lp_b0_h*L_ap_low_lp_s1 + L_lp_b1_h*L_ap_low_lp2_x1p + L_lp_b2_h*L_ap_low_lp2_x2p\n            - L_lp_a1_h*L_ap_low_lp2_y1p - L_lp_a2_h*L_ap_low_lp2_y2p;\nL_ap_low_lp2_x2 = L_ap_low_lp2_x1p; L_ap_low_lp2_x1 = L_ap_low_lp_s1;\nL_ap_low_lp2_y2 = L_ap_low_lp2_y1p; L_ap_low_lp2_y1 = L_ap_low_lp;\n\n// L_All-L_pass L_HP L_stage 1 L_sobre L_low_raw\nL_ap_low_hp1_x1p = L_ap_low_hp1_x1; L_ap_low_hp1_x2p = L_ap_low_hp1_x2;\nL_ap_low_hp1_y1p = L_ap_low_hp1_y1; L_ap_low_hp1_y2p = L_ap_low_hp1_y2;\nL_ap_low_hp_s1 = L_hp_b0_h*L_low_raw + L_hp_b1_h*L_ap_low_hp1_x1p + L_hp_b2_h*L_ap_low_hp1_x2p\n               - L_hp_a1_h*L_ap_low_hp1_y1p - L_hp_a2_h*L_ap_low_hp1_y2p;\nL_ap_low_hp1_x2 = L_ap_low_hp1_x1p; L_ap_low_hp1_x1 = L_low_raw;\nL_ap_low_hp1_y2 = L_ap_low_hp1_y1p; L_ap_low_hp1_y1 = L_ap_low_hp_s1;\n\n// L_All-L_pass L_HP L_stage 2\nL_ap_low_hp2_x1p = L_ap_low_hp2_x1; L_ap_low_hp2_x2p = L_ap_low_hp2_x2;\nL_ap_low_hp2_y1p = L_ap_low_hp2_y1; L_ap_low_hp2_y2p = L_ap_low_hp2_y2;\nL_ap_low_hp = L_hp_b0_h*L_ap_low_hp_s1 + L_hp_b1_h*L_ap_low_hp2_x1p + L_hp_b2_h*L_ap_low_hp2_x2p\n            - L_hp_a1_h*L_ap_low_hp2_y1p - L_hp_a2_h*L_ap_low_hp2_y2p;\nL_ap_low_hp2_x2 = L_ap_low_hp2_x1p; L_ap_low_hp2_x1 = L_ap_low_hp_s1;\nL_ap_low_hp2_y2 = L_ap_low_hp2_y1p; L_ap_low_hp2_y1 = L_ap_low_hp;\n\n// L_LOW L_compensado (L_all-L_pass L_reconstruye L_la señal L_con L_el L_mismo L_delay L_que L_mid/L_high)\nL_low = L_ap_low_lp + L_ap_low_hp;\n\n// ===== L_SEGUNDO L_CORTE @ L_hiF L_sobre L_REST: L_mid (L_LP) L_y L_high (L_HP) =====\n\n// L_LP L_Stage 1 L_para L_MID\nL_m1_x1p = L_m1_x1; L_m1_x2p = L_m1_x2; L_m1_y1p = L_m1_y1; L_m1_y2p = L_m1_y2;\nL_mid_s1 = L_lp_b0_h*L_rest + L_lp_b1_h*L_m1_x1p + L_lp_b2_h*L_m1_x2p - L_lp_a1_h*L_m1_y1p - L_lp_a2_h*L_m1_y2p;\nL_m1_x2 = L_m1_x1p; L_m1_x1 = L_rest; L_m1_y2 = L_m1_y1p; L_m1_y1 = L_mid_s1;\n\n// L_LP L_Stage 2 L_para L_MID\nL_m2_x1p = L_m2_x1; L_m2_x2p = L_m2_x2; L_m2_y1p = L_m2_y1; L_m2_y2p = L_m2_y2;\nL_mid = L_lp_b0_h*L_mid_s1 + L_lp_b1_h*L_m2_x1p + L_lp_b2_h*L_m2_x2p - L_lp_a1_h*L_m2_y1p - L_lp_a2_h*L_m2_y2p;\nL_m2_x2 = L_m2_x1p; L_m2_x1 = L_mid_s1; L_m2_y2 = L_m2_y1p; L_m2_y1 = L_mid;\n\n// L_HP L_Stage 1 L_para L_HIGH\nL_u1_x1p = L_u1_x1; L_u1_x2p = L_u1_x2; L_u1_y1p = L_u1_y1; L_u1_y2p = L_u1_y2;\nL_high_s1 = L_hp_b0_h*L_rest + L_hp_b1_h*L_u1_x1p + L_hp_b2_h*L_u1_x2p - L_hp_a1_h*L_u1_y1p - L_hp_a2_h*L_u1_y2p;\nL_u1_x2 = L_u1_x1p; L_u1_x1 = L_rest; L_u1_y2 = L_u1_y1p; L_u1_y1 = L_high_s1;\n\n// L_HP L_Stage 2 L_para L_HIGH\nL_u2_x1p = L_u2_x1; L_u2_x2p = L_u2_x2; L_u2_y1p = L_u2_y1; L_u2_y2p = L_u2_y2;\nL_high = L_hp_b0_h*L_high_s1 + L_hp_b1_h*L_u2_x1p + L_hp_b2_h*L_u2_x2p - L_hp_a1_h*L_u2_y1p - L_hp_a2_h*L_u2_y2p;\nL_u2_x2 = L_u2_x1p; L_u2_x1 = L_high_s1; L_u2_y2 = L_u2_y1p; L_u2_y1 = L_high;\n\n// ===== L_SALIDAS =====\nlowL = L_low;   // L_Graves L_compensados\nmidL = L_mid;   // L_Medios\nhighL = L_high;  // L_Agudos\n\n// === R_bindings ===\nR_loF = smoothHpfFreq;\nR_hiF = smoothLpfFreq;\n// R_Crossover R_LR4 R_de 3 R_bandas R_con compensación R_de R_fase R_correcta\n// out1: R_Low (20-250Hz)\n// out2: R_Mid (250-5kHz)\n// out3: R_High (5k-20kHz)\n// out4: R_Suma R_de R_las 3 R_bandas (R_debe R_hacer R_null R_test R_con R_entrada)\n\n// ===== R_DECLARACIONES =====\n// R_Estados R_para R_los 8 R_biquads R_del R_crossover R_principal\n// R_Low R_stage 1\n// R_Low R_stage 2\n// R_Rest R_HP R_stage 1\n// R_Rest R_HP R_stage 2\n// R_Mid R_LP R_stage 1\n// R_Mid R_LP R_stage 2\n// R_High R_HP R_stage 1\n// R_High R_HP R_stage 2\n\n// R_Estados R_para R_all-R_pass R_de compensación R_en R_la R_banda R_LOW\n// ===== R_PROCESO =====\nR_x = rTrimmed;\n\n// R_Proteger R_frecuencias\nR_sr = samplerate;\nR_loF = max(10, min(R_loF, 0.45 * R_sr));\nR_hiFr = max(10, min(R_hiF, 0.45 * R_sr));\nR_hiF = max(R_hiFr, R_loF + 1);\n\n// R_Constantes\nTWOPI = 6.283185307179586;\nR_QBW = 0.7071067811865476; // sqrt(2)/2 R_para R_Butterworth\n\n// === R_Coeficientes R_Butterworth @ R_loF ===\nR_w0_lo = TWOPI * R_loF / R_sr;\nR_cos_lo = cos(R_w0_lo);\nR_sin_lo = sin(R_w0_lo);\nR_alpha_lo = R_sin_lo / (2 * R_QBW);\nR_a0_lo = 1 + R_alpha_lo;\nR_a1_lo = -2 * R_cos_lo;\nR_a2_lo = 1 - R_alpha_lo;\n\n// R_LP @ R_loF (R_normalizado)\nR_lp_b0_l = ((1 - R_cos_lo) * 0.5) / R_a0_lo;\nR_lp_b1_l = (1 - R_cos_lo) / R_a0_lo;\nR_lp_b2_l = R_lp_b0_l;\nR_lp_a1_l = R_a1_lo / R_a0_lo;\nR_lp_a2_l = R_a2_lo / R_a0_lo;\n\n// R_HP @ R_loF (R_normalizado)\nR_hp_b0_l = ((1 + R_cos_lo) * 0.5) / R_a0_lo;\nR_hp_b1_l = -(1 + R_cos_lo) / R_a0_lo;\nR_hp_b2_l = R_hp_b0_l;\nR_hp_a1_l = R_lp_a1_l;\nR_hp_a2_l = R_lp_a2_l;\n\n// === R_Coeficientes R_Butterworth @ R_hiF ===\nR_w0_hi = TWOPI * R_hiF / R_sr;\nR_cos_hi = cos(R_w0_hi);\nR_sin_hi = sin(R_w0_hi);\nR_alpha_hi = R_sin_hi / (2 * R_QBW);\nR_a0_hi = 1 + R_alpha_hi;\nR_a1_hi = -2 * R_cos_hi;\nR_a2_hi = 1 - R_alpha_hi;\n\n// R_LP @ R_hiF (R_normalizado)\nR_lp_b0_h = ((1 - R_cos_hi) * 0.5) / R_a0_hi;\nR_lp_b1_h = (1 - R_cos_hi) / R_a0_hi;\nR_lp_b2_h = R_lp_b0_h;\nR_lp_a1_h = R_a1_hi / R_a0_hi;\nR_lp_a2_h = R_a2_hi / R_a0_hi;\n\n// R_HP @ R_hiF (R_normalizado)\nR_hp_b0_h = ((1 + R_cos_hi) * 0.5) / R_a0_hi;\nR_hp_b1_h = -(1 + R_cos_hi) / R_a0_hi;\nR_hp_b2_h = R_hp_b0_h;\nR_hp_a1_h = R_lp_a1_h;\nR_hp_a2_h = R_lp_a2_h;\n\n// ===== R_PRIMER R_CORTE @ R_loF: R_low (R_LP) R_y R_rest (R_HP) =====\n\n// R_LP R_Stage 1 R_para R_LOW\nR_l1_x1p = R_l1_x1; R_l1_x2p = R_l1_x2; R_l1_y1p = R_l1_y1; R_l1_y2p = R_l1_y2;\nR_low_s1 = R_lp_b0_l*R_x + R_lp_b1_l*R_l1_x1p + R_lp_b2_l*R_l1_x2p - R_lp_a1_l*R_l1_y1p - R_lp_a2_l*R_l1_y2p;\nR_l1_x2 = R_l1_x1p; R_l1_x1 = R_x; R_l1_y2 = R_l1_y1p; R_l1_y1 = R_low_s1;\n\n// R_LP R_Stage 2 R_para R_LOW\nR_l2_x1p = R_l2_x1; R_l2_x2p = R_l2_x2; R_l2_y1p = R_l2_y1; R_l2_y2p = R_l2_y2;\nR_low_raw = R_lp_b0_l*R_low_s1 + R_lp_b1_l*R_l2_x1p + R_lp_b2_l*R_l2_x2p - R_lp_a1_l*R_l2_y1p - R_lp_a2_l*R_l2_y2p;\nR_l2_x2 = R_l2_x1p; R_l2_x1 = R_low_s1; R_l2_y2 = R_l2_y1p; R_l2_y1 = R_low_raw;\n\n// R_HP R_Stage 1 R_para R_REST\nR_h1_x1p = R_h1_x1; R_h1_x2p = R_h1_x2; R_h1_y1p = R_h1_y1; R_h1_y2p = R_h1_y2;\nR_rest_s1 = R_hp_b0_l*R_x + R_hp_b1_l*R_h1_x1p + R_hp_b2_l*R_h1_x2p - R_hp_a1_l*R_h1_y1p - R_hp_a2_l*R_h1_y2p;\nR_h1_x2 = R_h1_x1p; R_h1_x1 = R_x; R_h1_y2 = R_h1_y1p; R_h1_y1 = R_rest_s1;\n\n// R_HP R_Stage 2 R_para R_REST\nR_h2_x1p = R_h2_x1; R_h2_x2p = R_h2_x2; R_h2_y1p = R_h2_y1; R_h2_y2p = R_h2_y2;\nR_rest = R_hp_b0_l*R_rest_s1 + R_hp_b1_l*R_h2_x1p + R_hp_b2_l*R_h2_x2p - R_hp_a1_l*R_h2_y1p - R_hp_a2_l*R_h2_y2p;\nR_h2_x2 = R_h2_x1p; R_h2_x1 = R_rest_s1; R_h2_y2 = R_h2_y1p; R_h2_y1 = R_rest;\n\n// ===== COMPENSACIÓN R_ALL-R_PASS R_para R_LOW =====\n// R_Aplicamos R_un R_all-R_pass R_LP+R_HP @ R_hiF R_a R_la señal R_LOW R_para R_igualar R_el R_delay\n\n// R_All-R_pass R_LP R_stage 1 R_sobre R_low_raw\nR_ap_low_lp1_x1p = R_ap_low_lp1_x1; R_ap_low_lp1_x2p = R_ap_low_lp1_x2;\nR_ap_low_lp1_y1p = R_ap_low_lp1_y1; R_ap_low_lp1_y2p = R_ap_low_lp1_y2;\nR_ap_low_lp_s1 = R_lp_b0_h*R_low_raw + R_lp_b1_h*R_ap_low_lp1_x1p + R_lp_b2_h*R_ap_low_lp1_x2p\n               - R_lp_a1_h*R_ap_low_lp1_y1p - R_lp_a2_h*R_ap_low_lp1_y2p;\nR_ap_low_lp1_x2 = R_ap_low_lp1_x1p; R_ap_low_lp1_x1 = R_low_raw;\nR_ap_low_lp1_y2 = R_ap_low_lp1_y1p; R_ap_low_lp1_y1 = R_ap_low_lp_s1;\n\n// R_All-R_pass R_LP R_stage 2\nR_ap_low_lp2_x1p = R_ap_low_lp2_x1; R_ap_low_lp2_x2p = R_ap_low_lp2_x2;\nR_ap_low_lp2_y1p = R_ap_low_lp2_y1; R_ap_low_lp2_y2p = R_ap_low_lp2_y2;\nR_ap_low_lp = R_lp_b0_h*R_ap_low_lp_s1 + R_lp_b1_h*R_ap_low_lp2_x1p + R_lp_b2_h*R_ap_low_lp2_x2p\n            - R_lp_a1_h*R_ap_low_lp2_y1p - R_lp_a2_h*R_ap_low_lp2_y2p;\nR_ap_low_lp2_x2 = R_ap_low_lp2_x1p; R_ap_low_lp2_x1 = R_ap_low_lp_s1;\nR_ap_low_lp2_y2 = R_ap_low_lp2_y1p; R_ap_low_lp2_y1 = R_ap_low_lp;\n\n// R_All-R_pass R_HP R_stage 1 R_sobre R_low_raw\nR_ap_low_hp1_x1p = R_ap_low_hp1_x1; R_ap_low_hp1_x2p = R_ap_low_hp1_x2;\nR_ap_low_hp1_y1p = R_ap_low_hp1_y1; R_ap_low_hp1_y2p = R_ap_low_hp1_y2;\nR_ap_low_hp_s1 = R_hp_b0_h*R_low_raw + R_hp_b1_h*R_ap_low_hp1_x1p + R_hp_b2_h*R_ap_low_hp1_x2p\n               - R_hp_a1_h*R_ap_low_hp1_y1p - R_hp_a2_h*R_ap_low_hp1_y2p;\nR_ap_low_hp1_x2 = R_ap_low_hp1_x1p; R_ap_low_hp1_x1 = R_low_raw;\nR_ap_low_hp1_y2 = R_ap_low_hp1_y1p; R_ap_low_hp1_y1 = R_ap_low_hp_s1;\n\n// R_All-R_pass R_HP R_stage 2\nR_ap_low_hp2_x1p = R_ap_low_hp2_x1; R_ap_low_hp2_x2p = R_ap_low_hp2_x2;\nR_ap_low_hp2_y1p = R_ap_low_hp2_y1; R_ap_low_hp2_y2p = R_ap_low_hp2_y2;\nR_ap_low_hp = R_hp_b0_h*R_ap_low_hp_s1 + R_hp_b1_h*R_ap_low_hp2_x1p + R_hp_b2_h*R_ap_low_hp2_x2p\n            - R_hp_a1_h*R_ap_low_hp2_y1p - R_hp_a2_h*R_ap_low_hp2_y2p;\nR_ap_low_hp2_x2 = R_ap_low_hp2_x1p; R_ap_low_hp2_x1 = R_ap_low_hp_s1;\nR_ap_low_hp2_y2 = R_ap_low_hp2_y1p; R_ap_low_hp2_y1 = R_ap_low_hp;\n\n// R_LOW R_compensado (R_all-R_pass R_reconstruye R_la señal R_con R_el R_mismo R_delay R_que R_mid/R_high)\nR_low = R_ap_low_lp + R_ap_low_hp;\n\n// ===== R_SEGUNDO R_CORTE @ R_hiF R_sobre R_REST: R_mid (R_LP) R_y R_high (R_HP) =====\n\n// R_LP R_Stage 1 R_para R_MID\nR_m1_x1p = R_m1_x1; R_m1_x2p = R_m1_x2; R_m1_y1p = R_m1_y1; R_m1_y2p = R_m1_y2;\nR_mid_s1 = R_lp_b0_h*R_rest + R_lp_b1_h*R_m1_x1p + R_lp_b2_h*R_m1_x2p - R_lp_a1_h*R_m1_y1p - R_lp_a2_h*R_m1_y2p;\nR_m1_x2 = R_m1_x1p; R_m1_x1 = R_rest; R_m1_y2 = R_m1_y1p; R_m1_y1 = R_mid_s1;\n\n// R_LP R_Stage 2 R_para R_MID\nR_m2_x1p = R_m2_x1; R_m2_x2p = R_m2_x2; R_m2_y1p = R_m2_y1; R_m2_y2p = R_m2_y2;\nR_mid = R_lp_b0_h*R_mid_s1 + R_lp_b1_h*R_m2_x1p + R_lp_b2_h*R_m2_x2p - R_lp_a1_h*R_m2_y1p - R_lp_a2_h*R_m2_y2p;\nR_m2_x2 = R_m2_x1p; R_m2_x1 = R_mid_s1; R_m2_y2 = R_m2_y1p; R_m2_y1 = R_mid;\n\n// R_HP R_Stage 1 R_para R_HIGH\nR_u1_x1p = R_u1_x1; R_u1_x2p = R_u1_x2; R_u1_y1p = R_u1_y1; R_u1_y2p = R_u1_y2;\nR_high_s1 = R_hp_b0_h*R_rest + R_hp_b1_h*R_u1_x1p + R_hp_b2_h*R_u1_x2p - R_hp_a1_h*R_u1_y1p - R_hp_a2_h*R_u1_y2p;\nR_u1_x2 = R_u1_x1p; R_u1_x1 = R_rest; R_u1_y2 = R_u1_y1p; R_u1_y1 = R_high_s1;\n\n// R_HP R_Stage 2 R_para R_HIGH\nR_u2_x1p = R_u2_x1; R_u2_x2p = R_u2_x2; R_u2_y1p = R_u2_y1; R_u2_y2p = R_u2_y2;\nR_high = R_hp_b0_h*R_high_s1 + R_hp_b1_h*R_u2_x1p + R_hp_b2_h*R_u2_x2p - R_hp_a1_h*R_u2_y1p - R_hp_a2_h*R_u2_y2p;\nR_u2_x2 = R_u2_x1p; R_u2_x1 = R_high_s1; R_u2_y2 = R_u2_y1p; R_u2_y1 = R_high;\n\n// ===== R_SALIDAS =====\nlowR = R_low;   // R_Graves R_compensados\nmidR = R_mid;   // R_Medios\nhighR = R_high;  // R_Agudos\n\n\n// Selector de banda (0=low, 1=mid, 2=high) con suavizado (smoothedBand)\nwLow = max(0, 1 - abs(smoothedBand - 0));\nwMid = max(0, 1 - abs(smoothedBand - 1));\nwHigh = max(0, 1 - abs(smoothedBand - 2));\nwSum = max(1e-9, wLow + wMid + wHigh);\nwLow /= wSum; wMid /= wSum; wHigh /= wSum;\n\n// Banda a procesar y suma limpia para recomponer\npreBandL = wLow*lowL + wMid*midL + wHigh*highL;\npreBandR = wLow*lowR + wMid*midR + wHigh*highR;\nsumBandsL = lowL + midL + highL;\nsumBandsR = lowR + midR + highR;\nbypassWhenActiveL = sumBandsL - preBandL;\nbypassWhenActiveR = sumBandsR - preBandR;\n\n// Conmutación por enable (scSm): si desactivado, banda ancha\npreDistInL = mix(lTrimmed, preBandL, scSm);\npreDistInR = mix(rTrimmed, preBandR, scSm);\n\n// Allpass de compensación solo para la rama dry cuando crossover activo\n// === L_AP bindings ===\nL_loF = smoothHpfFreq;\nL_hiF = smoothLpfFreq;\n// L_All-L_pass L_LR4 L_de compensación L_para L_null L_test L_externo\n// L_Aplica L_el L_mismo L_delay L_de L_grupo L_que L_el L_crossover L_LR4\n// L_Para L_usar L_en L_la línea L_dry L_fuera L_del L_crossover\n\n// Parámetros (L_deben L_coincidir L_con L_los L_del L_crossover)\n// L_Estados L_para L_primer L_all-L_pass @ L_loF\n// L_Estados L_para L_segundo L_all-L_pass @ L_hiF\n// L_Entrada\nL_x = lTrimmed;\n\n// L_Constantes\nTWOPI = 6.283185307179586;\nL_QBW = 0.7071067811865476; // sqrt(2)/2 L_para L_Butterworth\n\n// L_Proteger L_frecuencias\nL_sr = samplerate;\nL_loF = max(10, min(L_loF, 0.45 * L_sr));\nL_hiFr = max(10, min(L_hiF, 0.45 * L_sr));\nL_hiF = max(L_hiFr, L_loF + 1);\n\n// === L_Coeficientes L_Butterworth @ L_loF ===\nL_w0_lo = TWOPI * L_loF / L_sr;\nL_cos_lo = cos(L_w0_lo);\nL_sin_lo = sin(L_w0_lo);\nL_alpha_lo = L_sin_lo / (2 * L_QBW);\nL_a0_lo = 1 + L_alpha_lo;\nL_a1_lo = -2 * L_cos_lo;\nL_a2_lo = 1 - L_alpha_lo;\n\n// L_LP @ L_loF (L_normalizado)\nL_lp_b0_l = ((1 - L_cos_lo) * 0.5) / L_a0_lo;\nL_lp_b1_l = (1 - L_cos_lo) / L_a0_lo;\nL_lp_b2_l = L_lp_b0_l;\nL_lp_a1_l = L_a1_lo / L_a0_lo;\nL_lp_a2_l = L_a2_lo / L_a0_lo;\n\n// L_HP @ L_loF (L_normalizado)\nL_hp_b0_l = ((1 + L_cos_lo) * 0.5) / L_a0_lo;\nL_hp_b1_l = -(1 + L_cos_lo) / L_a0_lo;\nL_hp_b2_l = L_hp_b0_l;\nL_hp_a1_l = L_lp_a1_l;\nL_hp_a2_l = L_lp_a2_l;\n\n// === L_Coeficientes L_Butterworth @ L_hiF ===\nL_w0_hi = TWOPI * L_hiF / L_sr;\nL_cos_hi = cos(L_w0_hi);\nL_sin_hi = sin(L_w0_hi);\nL_alpha_hi = L_sin_hi / (2 * L_QBW);\nL_a0_hi = 1 + L_alpha_hi;\nL_a1_hi = -2 * L_cos_hi;\nL_a2_hi = 1 - L_alpha_hi;\n\n// L_LP @ L_hiF (L_normalizado)\nL_lp_b0_h = ((1 - L_cos_hi) * 0.5) / L_a0_hi;\nL_lp_b1_h = (1 - L_cos_hi) / L_a0_hi;\nL_lp_b2_h = L_lp_b0_h;\nL_lp_a1_h = L_a1_hi / L_a0_hi;\nL_lp_a2_h = L_a2_hi / L_a0_hi;\n\n// L_HP @ L_hiF (L_normalizado)\nL_hp_b0_h = ((1 + L_cos_hi) * 0.5) / L_a0_hi;\nL_hp_b1_h = -(1 + L_cos_hi) / L_a0_hi;\nL_hp_b2_h = L_hp_b0_h;\nL_hp_a1_h = L_lp_a1_h;\nL_hp_a2_h = L_lp_a2_h;\n\n// === L_PRIMER L_ALL-L_PASS @ L_loF ===\n// L_LP L_Stage 1\nL_ap1_lp1_x1p = L_ap1_lp1_x1; L_ap1_lp1_x2p = L_ap1_lp1_x2;\nL_ap1_lp1_y1p = L_ap1_lp1_y1; L_ap1_lp1_y2p = L_ap1_lp1_y2;\nL_ap1_lp_s1 = L_lp_b0_l*L_x + L_lp_b1_l*L_ap1_lp1_x1p + L_lp_b2_l*L_ap1_lp1_x2p\n            - L_lp_a1_l*L_ap1_lp1_y1p - L_lp_a2_l*L_ap1_lp1_y2p;\nL_ap1_lp1_x2 = L_ap1_lp1_x1p; L_ap1_lp1_x1 = L_x;\nL_ap1_lp1_y2 = L_ap1_lp1_y1p; L_ap1_lp1_y1 = L_ap1_lp_s1;\n\n// L_LP L_Stage 2\nL_ap1_lp2_x1p = L_ap1_lp2_x1; L_ap1_lp2_x2p = L_ap1_lp2_x2;\nL_ap1_lp2_y1p = L_ap1_lp2_y1; L_ap1_lp2_y2p = L_ap1_lp2_y2;\nL_ap1_lp = L_lp_b0_l*L_ap1_lp_s1 + L_lp_b1_l*L_ap1_lp2_x1p + L_lp_b2_l*L_ap1_lp2_x2p\n         - L_lp_a1_l*L_ap1_lp2_y1p - L_lp_a2_l*L_ap1_lp2_y2p;\nL_ap1_lp2_x2 = L_ap1_lp2_x1p; L_ap1_lp2_x1 = L_ap1_lp_s1;\nL_ap1_lp2_y2 = L_ap1_lp2_y1p; L_ap1_lp2_y1 = L_ap1_lp;\n\n// L_HP L_Stage 1\nL_ap1_hp1_x1p = L_ap1_hp1_x1; L_ap1_hp1_x2p = L_ap1_hp1_x2;\nL_ap1_hp1_y1p = L_ap1_hp1_y1; L_ap1_hp1_y2p = L_ap1_hp1_y2;\nL_ap1_hp_s1 = L_hp_b0_l*L_x + L_hp_b1_l*L_ap1_hp1_x1p + L_hp_b2_l*L_ap1_hp1_x2p\n            - L_hp_a1_l*L_ap1_hp1_y1p - L_hp_a2_l*L_ap1_hp1_y2p;\nL_ap1_hp1_x2 = L_ap1_hp1_x1p; L_ap1_hp1_x1 = L_x;\nL_ap1_hp1_y2 = L_ap1_hp1_y1p; L_ap1_hp1_y1 = L_ap1_hp_s1;\n\n// L_HP L_Stage 2\nL_ap1_hp2_x1p = L_ap1_hp2_x1; L_ap1_hp2_x2p = L_ap1_hp2_x2;\nL_ap1_hp2_y1p = L_ap1_hp2_y1; L_ap1_hp2_y2p = L_ap1_hp2_y2;\nL_ap1_hp = L_hp_b0_l*L_ap1_hp_s1 + L_hp_b1_l*L_ap1_hp2_x1p + L_hp_b2_l*L_ap1_hp2_x2p\n         - L_hp_a1_l*L_ap1_hp2_y1p - L_hp_a2_l*L_ap1_hp2_y2p;\nL_ap1_hp2_x2 = L_ap1_hp2_x1p; L_ap1_hp2_x1 = L_ap1_hp_s1;\nL_ap1_hp2_y2 = L_ap1_hp2_y1p; L_ap1_hp2_y1 = L_ap1_hp;\n\n// L_Reconstruir L_primer L_all-L_pass\nL_stage1_out = L_ap1_lp + L_ap1_hp;\n\n// === L_SEGUNDO L_ALL-L_PASS @ L_hiF ===\n// L_LP L_Stage 1\nL_ap2_lp1_x1p = L_ap2_lp1_x1; L_ap2_lp1_x2p = L_ap2_lp1_x2;\nL_ap2_lp1_y1p = L_ap2_lp1_y1; L_ap2_lp1_y2p = L_ap2_lp1_y2;\nL_ap2_lp_s1 = L_lp_b0_h*L_stage1_out + L_lp_b1_h*L_ap2_lp1_x1p + L_lp_b2_h*L_ap2_lp1_x2p\n            - L_lp_a1_h*L_ap2_lp1_y1p - L_lp_a2_h*L_ap2_lp1_y2p;\nL_ap2_lp1_x2 = L_ap2_lp1_x1p; L_ap2_lp1_x1 = L_stage1_out;\nL_ap2_lp1_y2 = L_ap2_lp1_y1p; L_ap2_lp1_y1 = L_ap2_lp_s1;\n\n// L_LP L_Stage 2\nL_ap2_lp2_x1p = L_ap2_lp2_x1; L_ap2_lp2_x2p = L_ap2_lp2_x2;\nL_ap2_lp2_y1p = L_ap2_lp2_y1; L_ap2_lp2_y2p = L_ap2_lp2_y2;\nL_ap2_lp = L_lp_b0_h*L_ap2_lp_s1 + L_lp_b1_h*L_ap2_lp2_x1p + L_lp_b2_h*L_ap2_lp2_x2p\n         - L_lp_a1_h*L_ap2_lp2_y1p - L_lp_a2_h*L_ap2_lp2_y2p;\nL_ap2_lp2_x2 = L_ap2_lp2_x1p; L_ap2_lp2_x1 = L_ap2_lp_s1;\nL_ap2_lp2_y2 = L_ap2_lp2_y1p; L_ap2_lp2_y1 = L_ap2_lp;\n\n// L_HP L_Stage 1\nL_ap2_hp1_x1p = L_ap2_hp1_x1; L_ap2_hp1_x2p = L_ap2_hp1_x2;\nL_ap2_hp1_y1p = L_ap2_hp1_y1; L_ap2_hp1_y2p = L_ap2_hp1_y2;\nL_ap2_hp_s1 = L_hp_b0_h*L_stage1_out + L_hp_b1_h*L_ap2_hp1_x1p + L_hp_b2_h*L_ap2_hp1_x2p\n            - L_hp_a1_h*L_ap2_hp1_y1p - L_hp_a2_h*L_ap2_hp1_y2p;\nL_ap2_hp1_x2 = L_ap2_hp1_x1p; L_ap2_hp1_x1 = L_stage1_out;\nL_ap2_hp1_y2 = L_ap2_hp1_y1p; L_ap2_hp1_y1 = L_ap2_hp_s1;\n\n// L_HP L_Stage 2\nL_ap2_hp2_x1p = L_ap2_hp2_x1; L_ap2_hp2_x2p = L_ap2_hp2_x2;\nL_ap2_hp2_y1p = L_ap2_hp2_y1; L_ap2_hp2_y2p = L_ap2_hp2_y2;\nL_ap2_hp = L_hp_b0_h*L_ap2_hp_s1 + L_hp_b1_h*L_ap2_hp2_x1p + L_hp_b2_h*L_ap2_hp2_x2p\n         - L_hp_a1_h*L_ap2_hp2_y1p - L_hp_a2_h*L_ap2_hp2_y2p;\nL_ap2_hp2_x2 = L_ap2_hp2_x1p; L_ap2_hp2_x1 = L_ap2_hp_s1;\nL_ap2_hp2_y2 = L_ap2_hp2_y1p; L_ap2_hp2_y1 = L_ap2_hp;\n\n// L_Salida: señal L_con L_el L_mismo L_delay L_que L_el L_crossover L_LR4\ndryCompL = L_ap2_lp + L_ap2_hp;\n// === R_AP bindings ===\nR_loF = smoothHpfFreq;\nR_hiF = smoothLpfFreq;\n// R_All-R_pass R_LR4 R_de compensación R_para R_null R_test R_externo\n// R_Aplica R_el R_mismo R_delay R_de R_grupo R_que R_el R_crossover R_LR4\n// R_Para R_usar R_en R_la línea R_dry R_fuera R_del R_crossover\n\n// Parámetros (R_deben R_coincidir R_con R_los R_del R_crossover)\n// R_Estados R_para R_primer R_all-R_pass @ R_loF\n// R_Estados R_para R_segundo R_all-R_pass @ R_hiF\n// R_Entrada\nR_x = rTrimmed;\n\n// R_Constantes\nTWOPI = 6.283185307179586;\nR_QBW = 0.7071067811865476; // sqrt(2)/2 R_para R_Butterworth\n\n// R_Proteger R_frecuencias\nR_sr = samplerate;\nR_loF = max(10, min(R_loF, 0.45 * R_sr));\nR_hiFr = max(10, min(R_hiF, 0.45 * R_sr));\nR_hiF = max(R_hiFr, R_loF + 1);\n\n// === R_Coeficientes R_Butterworth @ R_loF ===\nR_w0_lo = TWOPI * R_loF / R_sr;\nR_cos_lo = cos(R_w0_lo);\nR_sin_lo = sin(R_w0_lo);\nR_alpha_lo = R_sin_lo / (2 * R_QBW);\nR_a0_lo = 1 + R_alpha_lo;\nR_a1_lo = -2 * R_cos_lo;\nR_a2_lo = 1 - R_alpha_lo;\n\n// R_LP @ R_loF (R_normalizado)\nR_lp_b0_l = ((1 - R_cos_lo) * 0.5) / R_a0_lo;\nR_lp_b1_l = (1 - R_cos_lo) / R_a0_lo;\nR_lp_b2_l = R_lp_b0_l;\nR_lp_a1_l = R_a1_lo / R_a0_lo;\nR_lp_a2_l = R_a2_lo / R_a0_lo;\n\n// R_HP @ R_loF (R_normalizado)\nR_hp_b0_l = ((1 + R_cos_lo) * 0.5) / R_a0_lo;\nR_hp_b1_l = -(1 + R_cos_lo) / R_a0_lo;\nR_hp_b2_l = R_hp_b0_l;\nR_hp_a1_l = R_lp_a1_l;\nR_hp_a2_l = R_lp_a2_l;\n\n// === R_Coeficientes R_Butterworth @ R_hiF ===\nR_w0_hi = TWOPI * R_hiF / R_sr;\nR_cos_hi = cos(R_w0_hi);\nR_sin_hi = sin(R_w0_hi);\nR_alpha_hi = R_sin_hi / (2 * R_QBW);\nR_a0_hi = 1 + R_alpha_hi;\nR_a1_hi = -2 * R_cos_hi;\nR_a2_hi = 1 - R_alpha_hi;\n\n// R_LP @ R_hiF (R_normalizado)\nR_lp_b0_h = ((1 - R_cos_hi) * 0.5) / R_a0_hi;\nR_lp_b1_h = (1 - R_cos_hi) / R_a0_hi;\nR_lp_b2_h = R_lp_b0_h;\nR_lp_a1_h = R_a1_hi / R_a0_hi;\nR_lp_a2_h = R_a2_hi / R_a0_hi;\n\n// R_HP @ R_hiF (R_normalizado)\nR_hp_b0_h = ((1 + R_cos_hi) * 0.5) / R_a0_hi;\nR_hp_b1_h = -(1 + R_cos_hi) / R_a0_hi;\nR_hp_b2_h = R_hp_b0_h;\nR_hp_a1_h = R_lp_a1_h;\nR_hp_a2_h = R_lp_a2_h;\n\n// === R_PRIMER R_ALL-R_PASS @ R_loF ===\n// R_LP R_Stage 1\nR_ap1_lp1_x1p = R_ap1_lp1_x1; R_ap1_lp1_x2p = R_ap1_lp1_x2;\nR_ap1_lp1_y1p = R_ap1_lp1_y1; R_ap1_lp1_y2p = R_ap1_lp1_y2;\nR_ap1_lp_s1 = R_lp_b0_l*R_x + R_lp_b1_l*R_ap1_lp1_x1p + R_lp_b2_l*R_ap1_lp1_x2p\n            - R_lp_a1_l*R_ap1_lp1_y1p - R_lp_a2_l*R_ap1_lp1_y2p;\nR_ap1_lp1_x2 = R_ap1_lp1_x1p; R_ap1_lp1_x1 = R_x;\nR_ap1_lp1_y2 = R_ap1_lp1_y1p; R_ap1_lp1_y1 = R_ap1_lp_s1;\n\n// R_LP R_Stage 2\nR_ap1_lp2_x1p = R_ap1_lp2_x1; R_ap1_lp2_x2p = R_ap1_lp2_x2;\nR_ap1_lp2_y1p = R_ap1_lp2_y1; R_ap1_lp2_y2p = R_ap1_lp2_y2;\nR_ap1_lp = R_lp_b0_l*R_ap1_lp_s1 + R_lp_b1_l*R_ap1_lp2_x1p + R_lp_b2_l*R_ap1_lp2_x2p\n         - R_lp_a1_l*R_ap1_lp2_y1p - R_lp_a2_l*R_ap1_lp2_y2p;\nR_ap1_lp2_x2 = R_ap1_lp2_x1p; R_ap1_lp2_x1 = R_ap1_lp_s1;\nR_ap1_lp2_y2 = R_ap1_lp2_y1p; R_ap1_lp2_y1 = R_ap1_lp;\n\n// R_HP R_Stage 1\nR_ap1_hp1_x1p = R_ap1_hp1_x1; R_ap1_hp1_x2p = R_ap1_hp1_x2;\nR_ap1_hp1_y1p = R_ap1_hp1_y1; R_ap1_hp1_y2p = R_ap1_hp1_y2;\nR_ap1_hp_s1 = R_hp_b0_l*R_x + R_hp_b1_l*R_ap1_hp1_x1p + R_hp_b2_l*R_ap1_hp1_x2p\n            - R_hp_a1_l*R_ap1_hp1_y1p - R_hp_a2_l*R_ap1_hp1_y2p;\nR_ap1_hp1_x2 = R_ap1_hp1_x1p; R_ap1_hp1_x1 = R_x;\nR_ap1_hp1_y2 = R_ap1_hp1_y1p; R_ap1_hp1_y1 = R_ap1_hp_s1;\n\n// R_HP R_Stage 2\nR_ap1_hp2_x1p = R_ap1_hp2_x1; R_ap1_hp2_x2p = R_ap1_hp2_x2;\nR_ap1_hp2_y1p = R_ap1_hp2_y1; R_ap1_hp2_y2p = R_ap1_hp2_y2;\nR_ap1_hp = R_hp_b0_l*R_ap1_hp_s1 + R_hp_b1_l*R_ap1_hp2_x1p + R_hp_b2_l*R_ap1_hp2_x2p\n         - R_hp_a1_l*R_ap1_hp2_y1p - R_hp_a2_l*R_ap1_hp2_y2p;\nR_ap1_hp2_x2 = R_ap1_hp2_x1p; R_ap1_hp2_x1 = R_ap1_hp_s1;\nR_ap1_hp2_y2 = R_ap1_hp2_y1p; R_ap1_hp2_y1 = R_ap1_hp;\n\n// R_Reconstruir R_primer R_all-R_pass\nR_stage1_out = R_ap1_lp + R_ap1_hp;\n\n// === R_SEGUNDO R_ALL-R_PASS @ R_hiF ===\n// R_LP R_Stage 1\nR_ap2_lp1_x1p = R_ap2_lp1_x1; R_ap2_lp1_x2p = R_ap2_lp1_x2;\nR_ap2_lp1_y1p = R_ap2_lp1_y1; R_ap2_lp1_y2p = R_ap2_lp1_y2;\nR_ap2_lp_s1 = R_lp_b0_h*R_stage1_out + R_lp_b1_h*R_ap2_lp1_x1p + R_lp_b2_h*R_ap2_lp1_x2p\n            - R_lp_a1_h*R_ap2_lp1_y1p - R_lp_a2_h*R_ap2_lp1_y2p;\nR_ap2_lp1_x2 = R_ap2_lp1_x1p; R_ap2_lp1_x1 = R_stage1_out;\nR_ap2_lp1_y2 = R_ap2_lp1_y1p; R_ap2_lp1_y1 = R_ap2_lp_s1;\n\n// R_LP R_Stage 2\nR_ap2_lp2_x1p = R_ap2_lp2_x1; R_ap2_lp2_x2p = R_ap2_lp2_x2;\nR_ap2_lp2_y1p = R_ap2_lp2_y1; R_ap2_lp2_y2p = R_ap2_lp2_y2;\nR_ap2_lp = R_lp_b0_h*R_ap2_lp_s1 + R_lp_b1_h*R_ap2_lp2_x1p + R_lp_b2_h*R_ap2_lp2_x2p\n         - R_lp_a1_h*R_ap2_lp2_y1p - R_lp_a2_h*R_ap2_lp2_y2p;\nR_ap2_lp2_x2 = R_ap2_lp2_x1p; R_ap2_lp2_x1 = R_ap2_lp_s1;\nR_ap2_lp2_y2 = R_ap2_lp2_y1p; R_ap2_lp2_y1 = R_ap2_lp;\n\n// R_HP R_Stage 1\nR_ap2_hp1_x1p = R_ap2_hp1_x1; R_ap2_hp1_x2p = R_ap2_hp1_x2;\nR_ap2_hp1_y1p = R_ap2_hp1_y1; R_ap2_hp1_y2p = R_ap2_hp1_y2;\nR_ap2_hp_s1 = R_hp_b0_h*R_stage1_out + R_hp_b1_h*R_ap2_hp1_x1p + R_hp_b2_h*R_ap2_hp1_x2p\n            - R_hp_a1_h*R_ap2_hp1_y1p - R_hp_a2_h*R_ap2_hp1_y2p;\nR_ap2_hp1_x2 = R_ap2_hp1_x1p; R_ap2_hp1_x1 = R_stage1_out;\nR_ap2_hp1_y2 = R_ap2_hp1_y1p; R_ap2_hp1_y1 = R_ap2_hp_s1;\n\n// R_HP R_Stage 2\nR_ap2_hp2_x1p = R_ap2_hp2_x1; R_ap2_hp2_x2p = R_ap2_hp2_x2;\nR_ap2_hp2_y1p = R_ap2_hp2_y1; R_ap2_hp2_y2p = R_ap2_hp2_y2;\nR_ap2_hp = R_hp_b0_h*R_ap2_hp_s1 + R_hp_b1_h*R_ap2_hp2_x1p + R_hp_b2_h*R_ap2_hp2_x2p\n         - R_hp_a1_h*R_ap2_hp2_y1p - R_hp_a2_h*R_ap2_hp2_y2p;\nR_ap2_hp2_x2 = R_ap2_hp2_x1p; R_ap2_hp2_x1 = R_ap2_hp_s1;\nR_ap2_hp2_y2 = R_ap2_hp2_y1p; R_ap2_hp2_y1 = R_ap2_hp;\n\n// R_Salida: señal R_con R_el R_mismo R_delay R_que R_el R_crossover R_LR4\ndryCompR = R_ap2_lp + R_ap2_hp;\ndryL = mix(lIn, dryCompL, scSm);\ndryR = mix(rIn, dryCompR, scSm);\n\n// Entrada al bloque de TILT\nlLs = preDistInL;\nrLs = preDistInR;\n\n// Mapeo para TILT: usar la señal seleccionada por el crossover\nlFiltered = preDistInL;\nrFiltered = preDistInR;\n\n// -----------------------------------------------------------------------------\n// FILTRO TILT PRE-DISTORSIÓN\n// -----------------------------------------------------------------------------\nfc = 1000.0;     // 1 kHz como pivote del tilt\n// q ya no se usa en la versión RBJ del tilt (S=1 internamente)\n\n// Cálculo de coeficientes para Tilt (invertido para UI intuitiva)\n//tiltGain = dbtoa(-tiltDb);\n//omega = (fc * twopi) / samplerate;\n//sn = sin(omega);\n//cs = cos(omega);\n//A = sqrt(tiltGain);\n//beta = sqrt((A * A + 1) / q - (A - 1) * (A - 1));\n\n// RBJ cookbook prep (tilt = LS(-G) + HS(+G))\nomega = (fc * twopi) / samplerate;\nsn = sin(omega);\ncs = cos(omega);\n\n// Ganancias complementarias en dB\nGls = -tiltDb;               // Low-shelf: -G\nGhs =  tiltDb;               // High-shelf: +G\n\n// A = 10^(G/40)\nAls = sqrt(dbtoa(Gls));\nAhs = sqrt(dbtoa(Ghs));\n\n// Slope RBJ (S=1 es canónico y estable)\nS  = 1.0;\n\n// alpha para shelves (RBJ)\nalphaLs = 0.5 * sn * sqrt((Als + 1/Als) * (1/S - 1) + 2);\nalphaHs = 0.5 * sn * sqrt((Ahs + 1/Ahs) * (1/S - 1) + 2);\n\n// raíces de A (se usan en los términos 2*sqrt(A)*alpha)\nsqrtAls = sqrt(Als);\nsqrtAhs = sqrt(Ahs);\n\n// Coeficientes Low Shelf\n//b0Ls = 1 / ((A + 1) + (A - 1) * cs + beta * sn);\n//a0Ls = A * ((A + 1) - (A - 1) * cs + beta * sn) * b0Ls;\n//a1Ls = 2 * A * ((A - 1) - (A + 1) * cs) * b0Ls;\n//a2Ls = A * ((A + 1) - (A - 1) * cs - beta * sn) * b0Ls;\n//b1Ls = -2 * ((A - 1) + (A + 1) * cs) * b0Ls;\n//b2Ls = ((A + 1) + (A - 1) * cs - beta * sn) * b0Ls;\n\n// RBJ Low-Shelf (normalizado a a0)\nb0_ls =  Als * ((Als + 1) - (Als - 1) * cs + 2 * sqrtAls * alphaLs);\nb1_ls = 2*Als * ((Als - 1) - (Als + 1) * cs);\nb2_ls =  Als * ((Als + 1) - (Als - 1) * cs - 2 * sqrtAls * alphaLs);\n\na0_ls =        (Als + 1) + (Als - 1) * cs + 2 * sqrtAls * alphaLs;\na1_ls =   -2 * ((Als - 1) + (Als + 1) * cs);\na2_ls =        (Als + 1) + (Als - 1) * cs - 2 * sqrtAls * alphaLs;\n\n// Normalización\ninv_a0_ls = 1 / a0_ls;\na0Ls = b0_ls * inv_a0_ls;\na1Ls = b1_ls * inv_a0_ls;\na2Ls = b2_ls * inv_a0_ls;\nb1Ls = a1_ls * inv_a0_ls;\nb2Ls = a2_ls * inv_a0_ls;\n\n// Aplicar Low Shelf\n//lLs = a0Ls * lFiltered + a1Ls * tiltL2 + a2Ls * tiltL1 - b1Ls * tiltL4 - b2Ls * tiltL3;\n//tiltL1 = tiltL2;\n//tiltL2 = lFiltered;\n//tiltL3 = tiltL4;\n//tiltL4 = lLs;\n\n//rLs = a0Ls * rFiltered + a1Ls * tiltR2 + a2Ls * tiltR1 - b1Ls * tiltR4 - b2Ls * tiltR3;\n//tiltR1 = tiltR2;\n//tiltR2 = rFiltered;\n//tiltR3 = tiltR4;\n//tiltR4 = rLs;\n\n// Aplicar Low Shelf\nlLs = a0Ls * lFiltered + a1Ls * tiltLsL2 + a2Ls * tiltLsL1 - b1Ls * tiltLsL4 - b2Ls * tiltLsL3;\ntiltLsL1 = tiltLsL2;\ntiltLsL2 = lFiltered;\ntiltLsL3 = tiltLsL4;\ntiltLsL4 = lLs;\n\nrLs = a0Ls * rFiltered + a1Ls * tiltLsR2 + a2Ls * tiltLsR1 - b1Ls * tiltLsR4 - b2Ls * tiltLsR3;\ntiltLsR1 = tiltLsR2;\ntiltLsR2 = rFiltered;\ntiltLsR3 = tiltLsR4;\ntiltLsR4 = rLs;\n\n// Coeficientes High Shelf\n//aInv = sqrt(1/tiltGain);\n//betaHs = sqrt((aInv * aInv + 1) / q - (aInv - 1) * (aInv - 1));\n//b0Hs = 1 / ((aInv + 1) - (aInv - 1) * cs + betaHs * sn);\n//a0Hs = aInv * ((aInv + 1) + (aInv - 1) * cs + betaHs * sn) * b0Hs;\n//a1Hs = -2 * aInv * ((aInv - 1) + (aInv + 1) * cs) * b0Hs;\n//a2Hs = aInv * ((aInv + 1) + (aInv - 1) * cs - betaHs * sn) * b0Hs;\n//b1Hs = 2 * ((aInv - 1) - (aInv + 1) * cs) * b0Hs;\n//b2Hs = ((aInv + 1) - (aInv - 1) * cs - betaHs * sn) * b0Hs;\n\n// RBJ High-Shelf (normalizado a a0)\nb0_hs =  Ahs * ((Ahs + 1) + (Ahs - 1) * cs + 2 * sqrtAhs * alphaHs);\nb1_hs = -2*Ahs * ((Ahs - 1) + (Ahs + 1) * cs);\nb2_hs =  Ahs * ((Ahs + 1) + (Ahs - 1) * cs - 2 * sqrtAhs * alphaHs);\n\na0_hs =        (Ahs + 1) - (Ahs - 1) * cs + 2 * sqrtAhs * alphaHs;\na1_hs =    2 * ((Ahs - 1) - (Ahs + 1) * cs);\na2_hs =        (Ahs + 1) - (Ahs - 1) * cs - 2 * sqrtAhs * alphaHs;\n\n// Normalización\ninv_a0_hs = 1 / a0_hs;\na0Hs = b0_hs * inv_a0_hs;\na1Hs = b1_hs * inv_a0_hs;\na2Hs = b2_hs * inv_a0_hs;\nb1Hs = a1_hs * inv_a0_hs;\nb2Hs = a2_hs * inv_a0_hs;\n\n//lTilt = a0Hs * lLs + a1Hs * tiltL2 + a2Hs * tiltL1 - b1Hs * tiltL4 - b2Hs * tiltL3;\n//rTilt = a0Hs * rLs + a1Hs * tiltR2 + a2Hs * tiltR1 - b1Hs * tiltR4 - b2Hs * tiltR3;\n\nlTiltRaw = a0Hs * lLs + a1Hs * tiltHsL2 + a2Hs * tiltHsL1 - b1Hs * tiltHsL4 - b2Hs * tiltHsL3;\ntiltHsL1 = tiltHsL2;\ntiltHsL2 = lLs;\ntiltHsL3 = tiltHsL4;\ntiltHsL4 = lTiltRaw;\n\nrTiltRaw = a0Hs * rLs + a1Hs * tiltHsR2 + a2Hs * tiltHsR1 - b1Hs * tiltHsR4 - b2Hs * tiltHsR3;\ntiltHsR1 = tiltHsR2;\ntiltHsR2 = rLs;\ntiltHsR3 = tiltHsR4;\ntiltHsR4 = rTiltRaw;\n\n// Salida del bloque TILT (sin normalización aún)\n//lTilt = lTiltRaw;\n//rTilt = rTiltRaw;\n\n// Normalización en el pivote (fc)\ncosw = cs;           // ya calculados arriba\nsinw = sn;\ncos2 = (cs*cs - sn*sn);\nsin2 = (2*sn*cs);\n\n// Magnitud LS en fc\nnr_ls = a0Ls + a1Ls*cosw + a2Ls*cos2;\nni_ls = -(a1Ls*sinw + a2Ls*sin2);\ndr_ls = 1 + b1Ls*cosw + b2Ls*cos2;\ndi_ls = -(b1Ls*sinw + b2Ls*sin2);\nmag2_ls = (nr_ls*nr_ls + ni_ls*ni_ls) / max(1e-12, (dr_ls*dr_ls + di_ls*di_ls));\nmag_ls = sqrt(mag2_ls);\n\n// Magnitud HS en fc\nnr_hs = a0Hs + a1Hs*cosw + a2Hs*cos2;\nni_hs = -(a1Hs*sinw + a2Hs*sin2);\ndr_hs = 1 + b1Hs*cosw + b2Hs*cos2;\ndi_hs = -(b1Hs*sinw + b2Hs*sin2);\nmag2_hs = (nr_hs*nr_hs + ni_hs*ni_hs) / max(1e-12, (dr_hs*dr_hs + di_hs*di_hs));\nmag_hs = sqrt(mag2_hs);\n\n// Ganancia de normalización\ngPivot = 1 / max(1e-9, mag_ls * mag_hs);\n\n// Salida normalizada\nlTilt = lTiltRaw * gPivot;\nrTilt = rTiltRaw * gPivot;\n\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO DE DISTORSIÓN CON MORPHING\n// -----------------------------------------------------------------------------\n\n// Ejecutar TODOS los algoritmos con implementación consistente de DC\nsoftL, softR = softclip(lTilt, rTilt, drive, dc, ceiling);\nsigmL, sigmR = sigmoid(lTilt, rTilt, drive, dc, ceiling);\nrectL, rectR = rectF(lTilt, rTilt, drive, dc, ceiling);\nfuzz1L, fuzz1R = fuzzExp1(lTilt, rTilt, drive, dc, ceiling);\ntanhL, tanhR = tangenteHiperbolica(lTilt, rTilt, drive, dc, ceiling);\nrecthL, recthR = rectH(lTilt, rTilt, drive, dc, ceiling);\natanL, atanR = arctangent(lTilt, rTilt, drive, dc, ceiling);\nhardL, hardR = hardClip(lTilt, rTilt, drive, dc, ceiling);\n\n// Sistema de morphing continuo\nmode = smoothedMode;  // Usar el modo suavizado\n\n// Calcular pesos (ahora solo 8 algoritmos)\nw0 = max(0, 1 - abs(mode - 0));      // Softclip\nw1 = max(0, 1 - abs(mode - 1));      // Sigmoid\nw2 = max(0, 1 - abs(mode - 2));      // RectF\nw3 = max(0, 1 - abs(mode - 3));      // Fuzz1\nw4 = max(0, 1 - abs(mode - 4));      // TanH\nw5 = max(0, 1 - abs(mode - 5));      // RectH\nw6 = max(0, 1 - abs(mode - 6));      // Arctangent\nw7 = max(0, 1 - abs(mode - 7));      // HardClip\n\n// Normalizar pesos\nsumWeights = w0 + w1 + w2 + w3 + w4 + w5 + w6 + w7 + 0.0001;\nw0 /= sumWeights; w1 /= sumWeights; w2 /= sumWeights; w3 /= sumWeights;\nw4 /= sumWeights; w5 /= sumWeights; w6 /= sumWeights; w7 /= sumWeights;\n\n// Mezclar algoritmos\ndistL = softL * w0 + sigmL * w1 + rectL * w2 + fuzz1L * w3 +\n        tanhL * w4 + recthL * w5 + atanL * w6 + hardL * w7;\n\ndistR = softR * w0 + sigmR * w1 + rectR * w2 + fuzz1R * w3 +\n        tanhR * w4 + recthR * w5 + atanR * w6 + hardR * w7;\n\n// DC Blocker\nprocessedL = dcblock(distL);\nprocessedR = dcblock(distR);\n\n// -----------------------------------------------------------------------------\n// BIT CRUSHER Y DOWNSAMPLING OPCIONAL (ANTES DEL DRY/WET)\n// -----------------------------------------------------------------------------\n// Bit Crusher\nbitL, bitR = bitCrusher(processedL, processedR, bits);\nbcL = dcblock(bitL);\nbcR = dcblock(bitR);\n\nwithBitCrusherL = mix(processedL, bcL, bitson);\nwithBitCrusherR = mix(processedR, bcR, bitson);\n\n// Downsampling con phasor y latch\n// Calcular frecuencia del decimador basada en el parámetro\n// Convertir el parámetro (0-99) a factor de decimación entero (1-100)\ndeciFactor = max(1, floor(hDownsample + 1));\ndeciFreq   = samplerate / deciFactor;   // 1 latch por cada N muestras\n\n// Edge de activación (reset de fase al pasar de OFF→ON)\nenableNow  = downsampleOn > 0.5;\nenableEdge = enableNow > dsEnablePrev;   // flanco de subida\ndsEnablePrev = enableNow;\n\n// Phasor manual 0..1 con reset en el flanco de activación\ninc = 1 / deciFactor;                   // equivalente a deciFreq/samplerate, más claro\ndsPhase = enableEdge ? 0 : (dsPhase + inc);\ndsPhase = dsPhase - floor(dsPhase);\n\n// Disparo robusto: en el wrap-around (fase actual < fase anterior) o si N==1\ndsEdgeWrap = dsPhase < dsTrigPrev;      // usa dsTrigPrev como \"fase previa\"\ndsEdge = (enableEdge + dsEdgeWrap + (deciFactor == 1)) > 0.5;\ndsTrigPrev = dsPhase;\n\n// Latch SOLO en el flanco\ndsHeldL = latch(withBitCrusherL, dsEdge);\ndsHeldR = latch(withBitCrusherR, dsEdge);\n\n// Aplicar downsampling\nwetFinalL = mix(withBitCrusherL, dsHeldL, downsampleOn);\nwetFinalR = mix(withBitCrusherR, dsHeldR, downsampleOn);\n\n// -----------------------------------------------------------------------------\n// OUTPUT MAKEUP (SOLO A LA SEÑAL WET)\n// -----------------------------------------------------------------------------\n// Aplicar makeup gain ANTES del dry/wet para que solo afecte a la señal procesada\n//wetWithMakeupL = wetFinalL * outputMakeupLinear + bypassWhenActiveL;\n//wetWithMakeupR = wetFinalR * outputMakeupLinear + bypassWhenActiveR;\nwetWithMakeupL = (wetFinalL * outputMakeupLinear) + (bypassWhenActiveL * scSm);\nwetWithMakeupR = (wetFinalR * outputMakeupLinear) + (bypassWhenActiveR * scSm);\n\n// -----------------------------------------------------------------------------\n// MEZCLA DRY/WET\n// -----------------------------------------------------------------------------\n// Dry = señal original sin procesar (pre-trim, pre-filtros)\n// Wet = señal completamente procesada (trim + filtros + tilt + distorsión + efectos + makeup)\n// Parámetro drywet: 0 = solo dry, 1 = solo wet\nmixedL = mix(dryL, wetWithMakeupL, drywet);\nmixedR = mix(dryR, wetWithMakeupR, drywet);\n\n// -----------------------------------------------------------------------------\n// SALIDA FINAL CON BYPASS\n// -----------------------------------------------------------------------------\n// Ya no aplicamos makeup aquí porque ya está en la señal wet\nfinalL = mixedL;\nfinalR = mixedR;\n\n// DC Blocker final antes de la salida\nfinalDcBlockedL = dcblock(finalL);\nfinalDcBlockedR = dcblock(finalR);\n\n// Salidas principales\nout1 = mix(lIn, finalDcBlockedL, bypass);\nout2 = mix(rIn, finalDcBlockedR, bypass);\n\n// Salida 3 vacía para mantener consistencia\nout3 = 0;\n\n// Salidas post Input Trim (para medidores)\nout4 = lTrimmed;  // L post trim\nout5 = rTrimmed;  // R post trim",
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
					"patching_rect" : [ 226.0, 419.0, 711.5, 22.0 ],
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
					"patching_rect" : [ 102.0, 19.0, 458.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1159.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 757.5, 357.0, 235.5, 357.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 446.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 705.5, 389.0, 235.5, 389.0 ],
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
					"midpoints" : [ 1140.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"midpoints" : [ 379.5, 549.0, 207.5, 549.0 ],
					"order" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"midpoints" : [ 379.5, 549.0, 529.5, 549.0 ],
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
					"midpoints" : [ 1171.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"midpoints" : [ 529.5, 653.04296875, 387.5, 653.04296875 ],
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
					"midpoints" : [ 408.625, 521.0, 557.5, 521.0 ],
					"order" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"midpoints" : [ 408.625, 517.953125, 446.5, 517.953125 ],
					"order" : 1,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"midpoints" : [ 235.5, 448.0, 254.5, 448.0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"midpoints" : [ 408.625, 451.5, 423.5, 451.5 ],
					"order" : 2,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"midpoints" : [ 235.5, 504.0, 182.5, 504.0 ],
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
					"midpoints" : [ 1535.5, 403.53515625, 235.5, 403.53515625 ],
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1203.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 841.5, 389.0, 235.5, 389.0 ],
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
					"midpoints" : [ 540.5, 389.5, 235.5, 389.5 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 926.5, 357.0, 235.5, 357.0 ],
					"source" : [ "obj-29", 0 ]
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
					"midpoints" : [ 1045.5, 389.0, 235.5, 389.0 ],
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
					"midpoints" : [ 972.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1270.5, 667.0, 1407.5, 667.0 ],
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
					"midpoints" : [ 207.5, 652.296875, 361.5, 652.296875 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1432.5, 387.0, 235.5, 387.0 ],
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
					"midpoints" : [ 1236.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 111.5, 98.0, 111.359375, 98.0, 111.359375, 388.8515625, 235.5, 388.8515625 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"midpoints" : [ 379.5, 608.0, 550.5, 608.0 ],
					"order" : 0,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 379.5, 608.5, 228.5, 608.5 ],
					"order" : 1,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1270.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-46", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1301.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 1159.5, 209.0, 1159.5, 209.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1514.5, 667.0, 1407.5, 667.0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1335.5, 389.0, 235.5, 389.0 ],
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
					"midpoints" : [ 1077.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1408.5, 617.5, 1407.5, 617.5 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 773.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 134.5, 388.7890625, 235.5, 388.7890625 ],
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
					"midpoints" : [ 620.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-7", 0 ]
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
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 264.5, 229.714952761627956, 236.5, 229.714952761627956 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 329.5, 228.523546511627956, 236.5, 228.523546511627956 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1108.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 48.5, 387.7578125, 235.5, 387.7578125 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 235.5, 229.953234011627956, 236.5, 229.953234011627956 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 287.5, 337.5, 928.0, 337.5 ],
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
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-87", 0 ]
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
 ],
		"parameters" : 		{
			"obj-121" : [ "HPF", "HPF", 0 ],
			"obj-122" : [ "LPF", "LPF", 0 ],
			"obj-44" : [ "number", "number", 0 ],
			"obj-71" : [ "number[1]", "number[1]", 0 ],
			"obj-74" : [ "number[2]", "number[2]", 0 ],
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
