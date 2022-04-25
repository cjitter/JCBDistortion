{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 2,
			"revision" : 2,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 1954.0, 62.0, 732.0, 302.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 2,
							"revision" : 2,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 1954.0, 62.0, 720.0, 504.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 2,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "dsp.gen",
										"rect" : [ 0.0, 0.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"bgcolor" : [ 0.086274509803922, 0.36078431372549, 1.0, 1.0 ],
													"id" : "obj-54",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 77.0, 100.0, 30.0, 22.0 ],
													"text" : "r ltilt"
												}

											}
, 											{
												"box" : 												{
													"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
													"id" : "obj-55",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 214.5, 100.0, 32.0, 22.0 ],
													"text" : "r rtilt"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-53",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 248.5, 100.0, 33.0, 22.0 ],
													"text" : "r par"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-45",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 180.5, 130.5, 87.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-44",
													"maxclass" : "newobj",
													"numinlets" : 3,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 130.5, 73.0, 22.0 ],
													"text" : "mix"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-43",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 498.0, 126.5, 29.0, 22.0 ],
													"text" : "r dc"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-37",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 100.0, 21.0, 22.0 ],
													"text" : "i 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-35",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 180.5, 100.0, 22.0, 22.0 ],
													"text" : "f 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-31",
													"maxclass" : "newobj",
													"numinlets" : 0,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 348.666666666666686, 130.5, 26.0, 22.0 ],
													"text" : "r dr"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-5",
													"linecount" : 3,
													"maxclass" : "newobj",
													"numinlets" : 4,
													"numoutlets" : 2,
													"outlettype" : [ "", "" ],
													"patching_rect" : [ 50.0, 156.5, 467.0, 49.0 ],
													"text" : "expr parabola(inl\\, inr\\, dr\\, dc) { cell = dbtoa(1/dr)\\; l\\, r = inl * (1 - (abs(inl*dr+(dc*1)) * 0.25))\\, inr * (1 - (abs(inr*dr+(dc*1)) * 0.25))\\; l\\, r = clip(l\\, -cell\\, cell)\\, clip(r\\, -cell\\, cell)\\; return l\\, r\\; } out1\\, out2 = parabola(in1\\, in2\\, in3\\, in4)\\;"
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 2 ],
													"source" : [ "obj-31", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-45", 0 ],
													"source" : [ "obj-35", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-44", 0 ],
													"source" : [ "obj-37", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 3 ],
													"source" : [ "obj-43", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 0 ],
													"source" : [ "obj-44", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-5", 1 ],
													"source" : [ "obj-45", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-44", 2 ],
													"midpoints" : [ 258.0, 126.25, 113.5, 126.25 ],
													"order" : 1,
													"source" : [ "obj-53", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-45", 2 ],
													"order" : 0,
													"source" : [ "obj-53", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-44", 1 ],
													"source" : [ "obj-54", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-45", 1 ],
													"source" : [ "obj-55", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 17.5, 376.0, 133.0, 22.0 ],
									"text" : "gen @title parabola_no"
								}

							}
, 							{
								"box" : 								{
									"code" : "parabola(inl, inr, dr, dc) { \r\n\t\r\ncell = dbtoa(1/dr);\t\r\nl, r = inl * (1 - (abs(inl*dr+dc) * 0.25)), inr * (1 - (abs(inr*dr+dc) * 0.25)); \r\nl, r = clip(l, -cell, cell), clip(r, -cell, cell); \r\n\r\nreturn l, r; \r\n} \r\n\r\n//out1, out2 = parabola(in1, in2, in3, in4);\r\n\r\nbitCrusher(inl, inr, bits) { \r\n\r\nsteps    = pow(2,bits)-1;\r\ninvSteps = 1/steps;\r\n\r\nl = ceil(inl*steps) * invSteps;\r\nr = ceil(inr*steps) * invSteps;\r\n\r\nreturn l, r; \r\n} \r\n\r\n// out1, out2 = bitCrusher(in1, in2, in3);\r\n\r\nrectH(inl, inr, dr, cell){ \r\nif (inl < 0) { inl = 0; } else { inl = inl; }; \r\nif (inr < 0) { inr = 0; } else { inr = inr; }; \r\nl, r = clip(inl*dr*0.25, -cell, cell), clip(inr*dr*0.25, -cell, cell); \r\nreturn l, r; \r\n\r\n} \r\n\r\n//out1, out2 = rectH(in1,in2,in3,in5);\r\n\r\nrectF(inl, inr, dr, cell){ \r\nl, r = clip(abs(inl*dr*0.5), -cell, cell), clip(abs(inr*dr*0.5), -cell, cell); \r\nreturn l, r; \r\n} \r\n\r\n//out1, out2 = rectF(in1, in2, in3, in5);\r\n\r\nfuzzExp1(inl, inr, dr, dc, cell) { \r\n\t\r\nsignl = 0; \r\nsignr = 0;\r\n\r\nif (inl < 0) {signl = -1;} else {signl = 1;}; \r\nif (inr < 0) {signr = -1;} else {signr = 1;}; \r\n\r\nl = signl * ((1-(exp(-1*abs(inl*(dr/6)+(dc*0.001))))) / (1-(exp(-1*(dr/6)+(dc*0.001))))); \r\nr = signr * ((1-(exp(-1*abs(inr*(dr/6)+(dc*0.001))))) / (1-(exp(-1*(dr/6)+(dc*0.001))))); \r\n\r\nl, r = clip(l, -cell, cell), clip(r, -cell, cell); \r\n\r\nreturn l, r; \r\n} \r\n\r\n//out1, out2 = fuzzExp1(in1, in2, in3, in4, in5);\r\n// l, r = clip(l, -cell, cell), clip(r, -cell, cell); \r\n\r\nfuzzExp2(inl, inr, dr, dc, cell) { \r\n\r\nsignl = 0; \r\nsignr = 0; \r\n\r\nif (inl < 0) { signl = -1; } else { signl = 1; }; \r\nif (inr < 0) { signr = -1; } else { signr = 1; }; \r\n\r\nl, r = inl*0.1, inr*0.1;\r\n\r\nl = signl * (-1*l*(dr)+(dc*0.005)) * ((1-(exp(abs(l)))/(exp()- 1))); \r\nr = signr * (-1*r*(dr)+(dc*0.005)) * ((1-(exp(abs(r)))/(exp()- 1))); \r\n\r\nl, r = clip(l, -cell, cell), clip(r, -cell, cell); \r\n\r\nreturn l, r; \r\n} \r\n\r\nout1, out2 = fuzzExp2(in1, in2, in3, in4, in5);\r\n\r\n//l *= 0.7071;\r\n//r *= 0.7071;\r\n\r\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-5",
									"maxclass" : "codebox",
									"numinlets" : 5,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 11.5, 14.0, 678.0, 339.0 ]
								}

							}
 ],
						"lines" : [  ]
					}
,
					"patching_rect" : [ 167.0, 142.0, 36.0, 22.0 ],
					"text" : "gen~"
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
