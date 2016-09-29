<ul class="nav nav-tabs">
    <li class="active"><a href="#today" data-toggle="tab">Today</a></li>
    <li><a href="#days7" data-toggle="tab">Last 7 days</a></li>
    <li><a href="#days30" data-toggle="tab">Last 30 days</a></li>
</ul>
<div class="panel activities-widget">
    <div class="panel-body tab-content">
        <div class="tab-pane active" id="today">
            <div class="col-xs-3 text-center">
                <?php $steps = $today['total_steps_goal'] ? 100 * $today['total_steps'] / $today['total_steps_goal'] : 0; ?>
                <div class="activity-log-chart green" data-percent="<?php print $steps; ?>">
                    <span class="percent"><?php print $today['total_steps']; ?>/<?php print $today['total_steps_goal']; ?></span>
                </div>
                <p>Steps</p>
            </div>
            <div class="col-xs-3 text-center">
                <?php $low = $today['time_active_low_goal'] ? 100 * $today['time_active_low'] / $today['time_active_low_goal'] : 0; ?>
                <div class="activity-log-chart red" data-percent="<?php print $low; ?>">
                    <span class="percent"><?php print $today['time_active_low']; ?>/<?php print $today['time_active_low_goal']; ?></span>
                </div>
                <p>Low</p>
            </div>
            <div class="col-xs-3 text-center">
                <?php $medium = $today['time_active_medium_goal'] ? 100 * $today['time_active_medium'] / $today['time_active_medium_goal'] : 0; ?>
                <div class="activity-log-chart yellow" data-percent="<?php print $medium; ?>">
                    <span class="percent"><?php print $today['time_active_medium']; ?>/<?php print $today['time_active_medium_goal']; ?></span>
                </div>
                <p>Moderate</p>
            </div>
            <div class="col-xs-3 text-center">
                <?php $high = $today['time_active_high_goal'] ? 100 * $today['time_active_high'] / $today['time_active_high_goal'] : 0; ?>
                <div class="activity-log-chart red" data-percent="<?php print $high; ?>">
                    <span class="percent"><?php print $today['time_active_high']; ?>/<?php print $today['time_active_high_goal']; ?></span>
                </div>
                <p>Vigorous</p>
            </div>
        </div>
        <div class="tab-pane" id="days7">
            <div id="activities-days7"></div>
            <ul class="clearfix">
                <li>
                    <input type="radio" name="days7_param" id="days7-param-step" value="step" checked="checked" />
                    <label for="days7-param-step">Step</label>
                </li>
                <li>
                    <input type="radio" name="days7_param" id="days7-param-low" value="low" />
                    <label for="days7-param-low">Low</label>
                </li>
                <li>
                    <input type="radio" name="days7_param" id="days7-param-medium" value="medium" />
                    <label for="days7-param-medium">Moderate</label>
                </li>
                <li>
                    <input type="radio" name="days7_param" id="days7-param-high" value="high" />
                    <label for="days7-param-high">Vigorous</label>
                </li>
            </ul>
        </div>
        <div class="tab-pane" id="days30">
            <div id="activities-days30"></div>
            <ul class="clearfix">
                <li>
                    <input type="radio" name="days30_param" id="days30-param-step" value="step" checked="checked" />
                    <label for="days30-param-step">Step</label>
                </li>
                <li>
                    <input type="radio" name="days30_param" id="days30-param-low" value="low" />
                    <label for="days30-param-low">Low</label>
                </li>
                <li>
                    <input type="radio" name="days30_param" id="days30-param-medium" value="medium" />
                    <label for="days30-param-medium">Moderate</label>
                </li>
                <li>
                    <input type="radio" name="days30_param" id="days30-param-high" value="high" />
                    <label for="days30-param-high">Vigorous</label>
                </li>
            </ul>
        </div>
    </div>
</div>
