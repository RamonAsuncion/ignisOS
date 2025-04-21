#ifndef _IO_H_
#define _IO_H_

// TODO: handle arch
// https://wiki.osdev.org/Inline_Assembly/Examples

#include <stdint.h>

static inline void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ("outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ("inb %w1, %b0" : "=a"(ret) : "Nd"(port) : "memory");
    return ret;
}

#endif /* _IO_H_ */
