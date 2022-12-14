//JB: 0

#ifndef HANDLER_H
#define HANDLER_H

#include "msg.h"

class Handler : private Message
{
    Msg d_Msg;

public:
    Handler()
    {
        d_Msg = Msg::ALERT;
    }
    Msg getMsg();
};

inline Message::Msg Handler::getMsg()
{
    return d_Msg;
}

#endif
/* JB:
   Ok, so you understood. Good :-)
   Just please stop the in-class implementations already.

   We don't like them because the function member implementations distract
   from the class definition, much like multiple levels of detail in a single
   function make it less readable.

   Time constraints, brevity, avoiding repeated code - there's all kinds of
   reasons to still use ICIs. After this course, we'll expect you to come up
   with your own set of rules, that will doubtlessly fit you better than ours
   ever did.
   Until then, you'll have to stick to ours, or pay in points of score.
 */
