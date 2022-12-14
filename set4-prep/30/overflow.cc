#include "bistream.ih"

int BiStreamBuffer::overflow(int ch)
{
    if (one_->sputc(ch) == EOF || two_->sputc(ch) == EOF)
        return EOF;

    return ch;
}