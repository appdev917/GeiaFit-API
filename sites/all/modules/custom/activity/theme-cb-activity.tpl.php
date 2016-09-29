<form>
                    <div class="row">
                    
                        <div class="col-md-6">
                            <div class="form-group"><input type="text" name="Weight" class="form-control" placeholder="Weight*"></div>
                            </div>
                            
                            <div class="col-md-6">
                            <div class="form-group">
                                <div class="styled-select">
                                    <select class="form-control" name="weight_select">
                                        <option value="kilo">By Kilo (KG)</option>
                                        <option value="pounds">By Pounds</option>
                                    </select>
                                </div>
                            </div>
                        </div>
                        
                    </div> <!-- End row -->
                    
                    <div id="activies" class="row clearfix">
                        <div class="col-md-6">
                        
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" name="hours_sleep" value="0"></div>
                            <input type="checkbox" name="sleep" id="sleep"><label for="sleep"><span></span>Sleeping</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" name="hours_watchtv" value="0"></div>
                            <input type="checkbox" name="watchtv" id="watchtv"><label for="watchtv"><span></span>Watching TV</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_destwork" value="0"></div>
                            <input type="checkbox" name="destwork" id="destwork"><label for="destwork"><span></span>Typing, Writing, Desk Work</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_walking17" value="0"></div>
                            <input type="checkbox" name="walking17" id="walking17"><label for="walking17"><span></span>Walking, very slow, 1.7mph</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_walking25" value="0"></div>
                            <input type="checkbox" name="walking25" id="walking25"><label for="walking25"><span></span>Walking, 2.5mph</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_bike50" value="0"></div>
                            <input type="checkbox" name="bike50" id="bike50"><label for="bike50"><span></span>Bicycling, very slow, 50 watts</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_walking30" value="0"></div>
                            <input type="checkbox" name="walking30" id="walking30"><label for="walking30"><span></span>Walking, 3.0 mph</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_home_exercise" value="0"></div>
                            <input type="checkbox" name="home_exercise" id="home_exercise"><label for="home_exercise"><span></span>Calisthenics, home exercises</label>
                            </div>
                                                        
                            </div><!-- End col-md-6 -->
                            
                            <div class="col-md-6">
                                                       
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_walking34" value="0"></div>
                            <input type="checkbox" name="walking34" id="walking34"><label for="walking34"><span></span>Walking 3.4 mph</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours"> Hours <input type="text" class="textboxEffect" name="hours_bike10mph" value="0"></div>
                            <input type="checkbox" name="bike10mph" id="bike10mph"><label for="bike10mph"><span></span>Bicycling, lower than 10 mph</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_bike100" value="0"></div>
                            <input type="checkbox" name="bike100" id="bike100"><label for="bike100"><span></span>Bicycling, stationary(100 watts)</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_jogging" value="0"> </div>
                            <input type="checkbox" name="jogging" id="jogging"><label for="jogging"><span></span>Jogging, general</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_calisthenics" value="0"></div>
                            <input type="checkbox" name="calisthenics" id="calisthenics"><label for="calisthenics"><span></span>Heavy calisthenics</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_jogging_run" value="0"></div>
                            <input type="checkbox" name="jogging_run" id="jogging_run"><label for="jogging_run"><span></span>Running jogging, in place</label>
                            </div>
                            
                            <div class="form-group">
                            <div class="hours">Hours <input type="text" class="textboxEffect" name="hours_rope_jump" value="0"></div>
                            <input type="checkbox" name="rope_jump" id="rope_jump"><label for="rope_jump"><span></span>Rope jumping</label>
                            </div>
                            
                        </div><!-- End col-md-6 -->
                        <input type="hidden" name="calculator" value="easy_burned"/>
                    </div><!-- End activities -->
                 </form>
                 
                 <p><em>*Remember to fill the hours input field.</em></p>
                
                <hr>
                
                <div class="row">
                    <div class="col-md-12 text-center"><button id="selectBtn" class="button_medium">Calculate</button></div>
                </div>
                
             
                <div class="result">
                    <h3>Result for Total calorie burned</h3>
                    <div id="easy_cal_burned" class="no_margin_bottom">0.0</div>
                    
                    <div class="row" id="activietes_detail">
                        <div class="col-md-12 text-left">
                            <h4>Light Intensity <span id="lia_total">0.0</span></h4>
                            <ul>
                                <li>Sleeping <span id="sleep_value"> 0.0</span></li>
                                <li>Watching television <span id="watchtv_value"> 0.0</span></li>
                                <li>Writing, desk work, typing <span id="destwork_value"> 0.0</span></li>
                                <li>Walking, 1.7 mph(2.7km/h) <span id="walking17_value"> 0.0</span></li>
                                <li>Walking, 2.5 mph <span id="walking25_value"> 0.0</span></li>
                            </ul>
                        </div>
                        <div class="col-md-12 text-left">
                            <h4>Moderate Intensity <span id="mia_total">0.0</span></h4>
                            <ul>
                                <li>Bicycling, 50 watts <span id="bike50_value">0.0</span></li>
                                <li>Walking 3.0 mph <span id="walking30_value">0.0</span></li>
                                <li>Calisthenics, home exercise <span id="home_exercise_value">0.0</span></li>
                                <li>Walking 3.4 mph <span id="walking34_value">0.0</span></li>
                                <li>Bicycling <span id="bike10mph_value">0.0</span></li>
                                <li>Bicycling, 100watts <span id="bike100_value">0.0</span></li>
                            </ul>
                        </div>
                        <div class="col-md-12 text-left">
                            <h4>Vigorous Intensity <span id="via_total">0.0</span></h4>
                            <ul>
                                <li>Jogging, general<span id="jogging_value">0.0</span></li>
                                <li>Heavy calisthenics <span id="calisthenics_value">0.0</span></li>
                                <li>Running jogging <span id="jogging_run_value">0.0</span></li>
                                <li>Rope jumping <span id="rope_jump_value">0.0</span></li>
                            </ul>
                        </div>
                    </div>
                </div><!-- End result -->