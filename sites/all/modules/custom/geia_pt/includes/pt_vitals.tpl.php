<div class="widget"><div class="widget-header"><h3><i class="fa fa-bar-chart-o"></i>Patients Vitals</h3></div>
    <div class="widget-content vitals-widget">
        <div id="vitals-chart"></div>
        <ul class="clearfix">
            <?php $i = 0; ?>
            <?php $periods = array_keys($params); ?>
            <?php foreach ($periods as $period): ?>
                <li>
                    <?php $checked = $i == 0 ? 'checked="checked"' : ''; ?>
                    <input type="radio" name="period" id="days<?php print $period; ?>" value="<?php print $period; ?>" <?php print $checked; ?> />
                    <label for="days<?php print $period; ?>"><?php print $period; ?> days</label>
                </li>
                <?php $i++; ?>
            <?php endforeach; ?>
        </ul>
        <ul class="clearfix">
            <?php $i = 0; ?>
            <?php foreach ($params[$period]['series'] as $key => $parameter): ?>
                <li>
                    <?php $checked = $i == 0 ? 'checked="checked"' : ''; ?>
                    <input type="radio" name="parameter" id="<?php print $key; ?>" value="<?php print $key; ?>" <?php print $checked; ?> />
                    <label for="<?php print $key; ?>"><?php print $parameter['label']; ?></label>
                </li>
                <?php $i++; ?>
            <?php endforeach; ?>
        </ul>
    </div>
</div>