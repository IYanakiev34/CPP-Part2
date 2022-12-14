#ifndef BISTREAM_H
#define BISTREAM_H

#include <ostream>

// Derive a class from streambuf
class BiStreamBuffer : public std::streambuf
{
public:
    // Constructor takes two ostream objects
    BiStreamBuffer(std::ostream &one, std::ostream &two)
        : one_(one.rdbuf()), two_(two.rdbuf()) {}

protected:
    // This function is called by the base streambuf class
    // when it needs to write a character to the output stream
    int_type overflow(int_type ch) override
    {
        // Write the character to both output streams
        if (one_->sputc(ch) == EOF || two_->sputc(ch) == EOF)
            return EOF;

        return ch;
    }

private:
    // The streambuf objects for the two output streams
    std::streambuf *one_;
    std::streambuf *two_;
};

// Derive a class from ostream
class BiStream : private BiStreamBuffer, public std::ostream
{
public:
    // Constructor takes two ostream objects
    BiStream(std::ostream &one, std::ostream &two) : BiStreamBuffer(one, two),
                                                     std::ostream(this)
    {
    }
};

#endif