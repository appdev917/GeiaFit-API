<style>.literally { width:100%; }</style>
<div class="panel panel-default">
    <div class="panel-heading">
        <h3 class="panel-title"><?php print ucfirst(t($image_type)) . ' ' . t('Image'); ?></h3>
    </div>
    <div class="panel-body">
        <div class="literally export"></div>
        <?php print render($form); ?>
    </div>
</div>
