/**
* @file
* Canvas js integration.
*/

(function ($) {
    Drupal.behaviors.drawingfield = {
        attach: function(context, settings) {
            var containerOne = document.getElementsByClassName('literally export')[0];
            var backgroundShapes = [];
            var backgroundImage = new Image();
            backgroundImage.src = Drupal.settings.geia_pt.backgroundImage;

            var shape = Drupal.settings.geia_pt.shape;
            if (shape == '') {
                backgroundShapes = [ LC.createShape('Image', {image: backgroundImage, x: 0, y: 0}) ];
            }

            var lc = LC.init(containerOne, {
                backgroundShapes: backgroundShapes,
                imageURLPrefix: '/sites/all/libraries/literallycanvas/img'
            });

            if (shape != '') {
                lc.loadSnapshot(JSON.parse(shape));
            }

            lc.on('drawingChange', function() {
                var image = lc.getImage().toDataURL();
                var shape = JSON.stringify(lc.getSnapshot());
                $("#image-data").val(image);
                $("#shape-data").val(shape);
            });
        }
    }
})(jQuery);
