#include "lvgl/lvgl.h"
#include "my_gui.h"

unsigned char speed = 0;

static void my_event_cb(lv_event_t *e)
{
    printf("hello world\n");
}


static void my_event_cb1(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_VALUE_CHANGED && speed == 0)
    {
        printf(">_<\n");
        speed = 1;
    }else if(code == LV_EVENT_VALUE_CHANGED && speed == 1)
    {
        printf("<_>\n");
        speed = 0;
    }
}




void my_gui(void)
{
    static lv_style_t style1,style2;
    lv_style_init(&style1);
    lv_style_init(&style2);
    lv_style_set_bg_color(&style1,lv_color_hex(0x000000));
    lv_style_set_bg_color(&style2,lv_color_hex(0x0000ff));




    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());

    lv_obj_set_size(obj1,800,480);
    lv_obj_set_align(obj1,LV_ALIGN_CENTER);
    lv_obj_add_style(obj1,&style1,LV_STATE_DEFAULT);
    lv_obj_add_style(obj1,&style2,LV_STATE_PRESSED);
    lv_obj_set_style_border_color(obj1,lv_color_hex(0x56c94c),LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj1,10,LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(obj1,100,LV_STATE_DEFAULT);

    lv_obj_set_style_outline_color(obj1,lv_color_hex(0x0000ff),LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(obj1,10,LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(obj1,100,LV_STATE_DEFAULT);

    lv_obj_add_event_cb(obj1,my_event_cb,LV_EVENT_CLICKED,NULL);






    lv_obj_t *label = lv_label_create(obj1);
    //lv_label_set_text_static(label,"hello");
    //lv_label_set_text_fmt(label,"V:%d dd",100);
    lv_obj_set_style_text_font(label,&lv_font_montserrat_30,LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(label,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(label,100,LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label,lv_color_hex(0x5084db),LV_STATE_DEFAULT);

    lv_label_set_recolor(label, true);
    lv_label_set_text(label,"ni #ff0000  hao# 22222  rsf f");
    lv_obj_set_size(label,400,30);



    lv_obj_t *button = lv_btn_create(lv_scr_act());
    lv_obj_set_size(button,100,50);
    lv_obj_set_align(button,LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(button,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(button,lv_color_hex(0x00ff00),LV_STATE_PRESSED);
    lv_obj_add_flag(button,LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(button,my_event_cb1,LV_EVENT_VALUE_CHANGED,NULL);

    lv_obj_t* label1 = lv_label_create(button);
    lv_obj_set_style_text_font(label1,&lv_font_montserrat_30,LV_PART_MAIN);
    lv_label_set_text(label1,"what?");
    lv_obj_set_align(label1,LV_ALIGN_CENTER);











































































}

