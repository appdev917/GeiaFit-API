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

        <div class="form-group"><input type="text" class="form-control" name="Height" placeholder="Height"></div>

        <div class="form-group">
            <div class="styled-select">
                <select class="form-control" name="height_select">
                    <option value="cm">By Centimeters (cm)</option>
                    <option value="inches">By Inches</option>
                </select>
            </div>
        </div>

        <div class="form-group add_top">
            <input type="radio" value="Male" name="Male" id="Male"><label for="Male" style="margin-right:30px;"><span></span>Male</label>
            <input type="radio" value="Female" name="Female" id="Female"><label for="Female"><span></span>Female</label>
        </div>

        <div class="form-group">
            <div class="styled-select">
                <select class="form-control" name="exercise_level">
                    <option value="nospec">None (stay in bed all day)</option>
                    <option value="sedentary">Sedentariness (very little)</option>
                    <option value="light">Light (1 to 3 days per week)</option>
                    <option value="moderate">Moderate (3 to 5 days per week)</option>
                    <option value="hard">Hard (6 days per week)</option>
                    <option value="nonstop">Non-Stop (You are Energizer Bunny.)</option>
                </select>
            </div>
        </div>                            
        <input type="hidden" name="calculator" value="daily_calorie">
    </form>
    <button id="selectBtn" class="button_medium add_top">Calculate</button>
</div><!-- End col-md-6 -->

<div class="col-md-6 col-sm-6">

    <div class="result">
        <h3>Your Daily Calories</h3>
        <div id="your_cal_intake">0.0</div>
    </div>
    <div class="result">
        <h3>Lowest Daily Calories</h3>
        <div id="bmr_value">0.0</div>
    </div>
</div><!-- End col-md-6-->
</div>