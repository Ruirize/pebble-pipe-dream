#include <pebble.h>

static Window *window_main;

static BitmapLayer *layer_background;

static GBitmap *bitmap_background;
static GBitmap *bitmap_tile;
static GBitmap *bitmap_pipe_connector_black;
static GBitmap *bitmap_pipe_connector_white;
static GBitmap *bitmap_pipe_elbow_black;
static GBitmap *bitmap_pipe_elbow_white;
static GBitmap *bitmap_pipe_horizontal_black;
static GBitmap *bitmap_pipe_horizontal_white;
static GBitmap *bitmap_pipe_plus_black;
static GBitmap *bitmap_pipe_plus_white;
static GBitmap *bitmap_pipe_tee_black;
static GBitmap *bitmap_pipe_tee_white;
static GBitmap *bitmap_pipe_vertical_black;
static GBitmap *bitmap_pipe_vertical_white;

static void window_main_load() {
  
}
static void window_main_unload() {
  
}

static void init() {
  window_main = window_create();
  window_set_fullscreen(window_main, true);
  window_set_background_color(window_main, GColorDarkCandyAppleRed);
  window_set_window_handlers(window_main, (WindowHandlers) {
    .load = window_main_load,
    .unload = window_main_unload
  });
  window_stack_push(window_main, true);
  
  bitmap_background = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  bitmap_tile = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_TILE);
  bitmap_pipe_connector_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_CONNECTOR_BLACK);
  bitmap_pipe_connector_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_CONNECTOR_WHITE);
  bitmap_pipe_elbow_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_ELBOW_BLACK);
  bitmap_pipe_elbow_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_ELBOW_WHITE);
  bitmap_pipe_horizontal_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_HORIZONTAL_BLACK);
  bitmap_pipe_horizontal_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_HORIZONTAL_WHITE);
  bitmap_pipe_plus_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_PLUS_BLACK);
  bitmap_pipe_plus_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_PLUS_WHITE);
  bitmap_pipe_tee_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_TEE_BLACK);
  bitmap_pipe_tee_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_TEE_WHITE);
  bitmap_pipe_vertical_black = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_VERTICAL_BLACK);
  bitmap_pipe_vertical_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PIPE_VERTICAL_WHITE);
  
  GColor8 *palette_background = gbitmap_get_palette(bitmap_background);
  palette_background[1] = (GColor8){.argb = 0b11001100};
  palette_background[3] = (GColor8){.argb = 0b11000100};
  gbitmap_set_palette(bitmap_background, palette_background, true);
  
  layer_background = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(layer_background, bitmap_background);

  layer_add_child(window_get_root_layer(window_main), bitmap_layer_get_layer(layer_background));
}
static void deinit() {
  window_destroy(window_main);
  
  gbitmap_destroy(bitmap_background);
  gbitmap_destroy(bitmap_tile);
  gbitmap_destroy(bitmap_pipe_connector_black);
  gbitmap_destroy(bitmap_pipe_connector_white);
  gbitmap_destroy(bitmap_pipe_elbow_black);
  gbitmap_destroy(bitmap_pipe_elbow_white);
  gbitmap_destroy(bitmap_pipe_horizontal_black);
  gbitmap_destroy(bitmap_pipe_horizontal_white);
  gbitmap_destroy(bitmap_pipe_plus_black);
  gbitmap_destroy(bitmap_pipe_plus_white);
  gbitmap_destroy(bitmap_pipe_tee_black);
  gbitmap_destroy(bitmap_pipe_tee_white);
  gbitmap_destroy(bitmap_pipe_vertical_black);
  gbitmap_destroy(bitmap_pipe_vertical_white);
}

int main() {
  init();
  app_event_loop();
  deinit();
}