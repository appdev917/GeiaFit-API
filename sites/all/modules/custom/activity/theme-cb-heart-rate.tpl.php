<div class="row">
                        <div class="col-md-6 col-sm-6">
                            <form>
                                <div class="form-group"><input type="text" class="form-control" name="Age" placeholder="Age (Years)"></div>
                                <div class="form-group"><input type="text" class="form-control" name="Weight" placeholder="Weight"></div>
                                
                                <div class="form-group">
                                    <div class="styled-select">
                                        <select class="form-control" name="weight_select">
                                            <option value="kilo">By Kilo (KG)</option>  
                                            <option value="pounds">By Pounds</option>
                                        </select>
                                    </div>
                                </div>
                                
                                <div class="form-group add_top">
                                    <input type="radio" value="Male" name="Male" id="Male"><label for="Male" style="margin-right:30px;"><span></span>Male</label>
                                    <input type="radio" value="Female" name="Female" id="Female"><label for="Female"><span></span>Female</label>
                                </div>
                                
                                <div class="form-group"><input type="text" class="form-control" name="heartrate" placeholder="Heart Rate BPM"></div>
                                <div class="form-group"><input type="text" class="form-control" name="duration" placeholder="Duration in minutes"></div>
                                <input type="hidden" name="calculator" value="adv_calculator">
                            </form>
                            <button id="selectBtn" class="button_medium add_top">Calculate</button>
                        </div>
                        
                        <div class="col-md-6 col-sm-6">
                            <div class="result">
                                <h3>Result for calorie burned</h3>
                                <div id="adv_calculator_value">0</div>
                            </div>   
                        </div>
                        
                    </div>