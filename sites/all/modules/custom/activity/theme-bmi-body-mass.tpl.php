
                    <div class="row">
                	<div class="col-md-6">
                         <form>
                            <div class="form-group"><input type="text"  class="form-control"  name="Weight"  placeholder="Weight"></div>
                            
                            <div class="form-group">
                            <div class="styled-select">
                            <select class="form-control col-md-3"  name="weight_select">
                            <option value="kilo">By Kilo (KG)</option>
                                  <option value="pounds">By Pounds</option>
                                </select>
                                </div>
                             </div>
                             
                            <div class="form-group"><input type="text"  class="form-control"  name="Height"  placeholder="Height"></div>
                            
                            <div class="form-group">
                            <div class="styled-select">
                            <select class="form-control"  name="height_select">
                                  <option value="cm">By Centimeters (cm)</option>
                              <option value="inches">By Inches</option>
                                </select>
                                </div>
                            </div>
        
                            <input type="hidden" name="calculator" value="bmi_calculator"/>
                        </form>
                        <button id="selectBtn"  class="button_medium add_top">Calculate</button>
                      </div>
                
                        <div class="col-md-6">
                              
                             <div class="result">
                                <h3>BMI Value for you</h3>
                                <div id="bmi_value">0</div>
                                <div id ="indicator"></div>
                             </div>
                             
                        </div>
                        </div><!-- End row -->
                        
                        <hr>
        
                        	<h3>The Indication for BMI Range</h3>
                                  <div class="table-responsive">
                                  <table class="table table-striped">
                                      <thead>
                                          <tr>
                                            <th>BMI Range</th>
                                            <th>Category</th>
                                          </tr>
                                        </thead>
                                        <tbody>
                                        <tr>
                                        <td>Less than 16.5</td>
                                        <td>Serverely Underweight</td>
                                      </tr>
                                      <tr>
                                        <td>16.5 - 18.5 </td>
                                        <td>Underweight</td>
                                      </tr>
                                      <tr>
                                        <td>18.5 - 25</td>
                                        <td>Normal</td>
                                      </tr>
                                      <tr>
                                        <td>25 - 30 </td>
                                        <td>Overweight</td>
                                      </tr>
                                      <tr>
                                        <td>30+ </td>
                                        <td>Obese</td>
                                      </tr>
                                      </tbody>
                                    </table> 
                                    </div><!-- End table responsive -->