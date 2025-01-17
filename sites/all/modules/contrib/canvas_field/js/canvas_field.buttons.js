/**
 *@file
 * Buttons should use the canvasButton theme function wherever
 * possible.  The entire canvasField object is passed into the
 * button constructor.  The button constructor is responsible
 * for defining its own onclick action.
 */
CanvasField.Buttons = {};

(function ($) {

/**
 * Theme canvasButton.
 *
 * This function should be used for any additional buttons so we can
 * override button sizes as needed.
 */
  Drupal.theme.prototype.canvasButton = function(src, title) {
    return $('<img class="toolbar-icon" src="' + src + '" title="' + title + '" />');
  }

  Drupal.theme.prototype.canvasButtonSet = function(buttons) {
    var wrapper = $('<div class="tools-wrapper"></div>');

    for (var key in buttons) {
      wrapper.append(buttons[key]);
    }
    
    return wrapper;
  }


  /**
 * Canvas Reset Button.
 */
  CanvasField.Buttons.Reset = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'delete.png';
    var button = Drupal.theme('canvasButton', icon, 'Reset/Clear');
    button.click(function() {
      canvasField.reset();
    });
    return button;
  }

  /**
 * Canvas Pen Button
 */
  CanvasField.Buttons.Pen = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'pencil.png';
    var button = Drupal.theme('canvasButton', icon, Drupal.t('Pen Tool'));
    button.bind('click', function() {
      canvasField.switchTool('Pen');
    });
    return button;
  }
  
  /**
 * Canvas Line Button
 */
  CanvasField.Buttons.Line = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'pencil.png';
    var button = Drupal.theme('canvasButton', icon, Drupal.t('Line Tool'));
    button.bind('click', function() {
      canvasField.switchTool('Line');
    });
    return button;
  }
  
  

  /**
 * Canvas Paint Tool Button
 */
  CanvasField.Buttons.Paint = function(canvasField) {
    if (typeof CanvasField.Tools.Paint == 'function') {
      var icon =  Drupal.settings.basePath + canvasField.settings.icon_path + 'paintcan.png';
      var button = Drupal.theme('canvasButton', icon, Drupal.t('Paint Tool'));
      button.bind('click', function() {
        canvasField.switchTool('Paint');
      });
      return button;
    }
  }

  /**
 * Canvas Configure Button
 */
  CanvasField.Buttons.Color = function(canvasField) {
    if (typeof $.farbtastic == 'function') {
      var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'color_wheel.png';
      var button = Drupal.theme('canvasButton', icon, Drupal.t('Configuration'));
      button.bind('click', function() {
        CanvasField.ConfigForm(canvasField.context);
      });
      return button;
    }
  }
  
/**
 * Canvas Tool Size Button Small.
 */
  CanvasField.Buttons.ToolSmall = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'small.png';
    var button = Drupal.theme('canvasButton', icon, 'Small size');
    button.click(function() {
      canvasField.toolSmall();
    });
    return button;
  }  
  
  /**
 * Canvas Tool Size Button Medium.
 */
  CanvasField.Buttons.ToolMedium = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'medium.png';
    var button = Drupal.theme('canvasButton', icon, 'Medium size');
    button.click(function() {
      canvasField.toolMedium();
    });
    return button;
  }  
  
  /**
 * Canvas Tool Size Button Large.
 */
  CanvasField.Buttons.ToolLarge = function(canvasField) {
    var icon = Drupal.settings.basePath + canvasField.settings.icon_path + 'large.png';
    var button = Drupal.theme('canvasButton', icon, 'Large size');
    button.click(function() {
      canvasField.toolLarge();
    });
    return button;
  }
  

  
  

  })(jQuery);