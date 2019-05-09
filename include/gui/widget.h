#ifndef __PLUTO__GUI__WIDGET_H
#define __PLUTO__GUI__WIDGET_H


#include <common/types.h>
#include <common/graphicscontext.h>
#include <drivers/hw/keyboard.h>

namespace pluto
{
    namespace gui
    {
        
        class Widget : public pluto::drivers::KeyboardEventHandler
        {
        protected:
            Widget* parent;
            common::int32_t x;
            common::int32_t y;
            common::int32_t w;
            common::int32_t h;
            
            common::uint8_t r;
            common::uint8_t g;
            common::uint8_t b;
            bool Focussable;

        public:

            Widget(Widget* parent,
                   common::int32_t x, common::int32_t y, common::int32_t w, common::int32_t h,
                   common::uint8_t r, common::uint8_t g, common::uint8_t b);
            ~Widget();
            
            virtual void GetFocus(Widget* widget);
            virtual void ModelToScreen(common::int32_t &x, common::int32_t& y);
            virtual bool ContainsCoordinate(common::int32_t x, common::int32_t y);
            
            virtual void Draw(common::GraphicsContext* gc);
            virtual void Move(common::int32_t y, common::int32_t x);
            virtual void Resize(common::int32_t w, common::int32_t h);
            virtual common::int32_t GetPositionY();
            virtual common::int32_t GetPositionX();
            virtual void OnMouseDown(common::int32_t x, common::int32_t y, common::uint8_t button);
            virtual void OnMouseUp(common::int32_t x, common::int32_t y, common::uint8_t button);
            virtual void OnMouseMove(common::int32_t oldx, common::int32_t oldy, common::int32_t newx, common::int32_t newy);
        };

    }
}


#endif