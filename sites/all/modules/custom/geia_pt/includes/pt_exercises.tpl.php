<div id="exercises" class="exercises pt-forms col-sm-10">
    <div class="col-xs-36">
        <h2>Patient Exercise Program</h2>
        <button class='btn btn-primary add_top' id='selectBtn'><a href="<?php print $webex_url; ?>" target='_new'>Find More Exercises on WebExercises</a></button>
        <p>Refesh this page after you complete exercise selection in WebEx</ap>
    </div>
    <div class="col-xs-36 col-md-24">
        <div class="exercise_list">
            <h3>Exercise List</h3>
            <?php  
                $exercise_form = drupal_get_form('geia_pt_update_exercises_form', $patient);
                print drupal_render($exercise_form);
            ?>
        </div>
    </div>
</div>
