#include "30.ih"

int BiStreamBuffer::overflow(int ch)
{
    if (d_one->sputc(ch) == EOF || d_two->sputc(ch) == EOF)
        return EOF;

    return ch;
}