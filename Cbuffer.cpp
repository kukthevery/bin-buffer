
/* ------------------------------------------------
 FILE:    NmcMessage.cc
 SUBJECT:
 AUTHOR:  Kukushkin Vladimir
 DATE:    Fri Aug  6 2004
 --------------------------------------------------*/

#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <assert.h>

#include "Cbuffer.h"

///////////////////////////////////////////////////////////////////////////////
/// BinaryBuffer
//-----------------------------------------------------------------------------
//--- Constructors & Destructors
BinaryBuffer::BinaryBuffer(int len, int capacity) :
    m_capacity(0),
    m_size(0),
    m_owner(false)
{
    // sanity check ( ... however could be another solutions for that)
    if(len > capacity)
    {
        capacity = len;
    }

    m_buffer = new char[capacity];
    if ( m_buffer )
    {
        m_capacity = capacity;
        m_size = len;
    }
    assert(m_buffer != NULL);
}

BinaryBuffer::BinaryBuffer(char* buf, int len, int capacity, bool owner) :
    m_capacity(0),
    m_size(0),
    m_owner(false)
{
    // sanity check ( ... however could be another solutions for that)
    if(len > capacity)
    {
        capacity = len;
    }

    m_buffer = new char[capacity];
    if ( m_buffer )
    {
        m_capacity = capacity;
        if(buf)
        {
            memcpy(m_buffer, buf, len);
            m_size = len;
        }
    }
    assert(m_buffer != NULL);
}

BinaryBuffer::~BinaryBuffer(void)
{
    if(m_buffer)
        delete m_buffer;
}

//-----------------------------------------------------------------------------

void BinaryBuffer::copy(char* str, int len)
{
    if ( len >= m_capacity )
    {
        if(m_buffer)
            delete m_buffer;
        m_buffer = new char[len];
        if(m_buffer)
            m_capacity = len;
    }
    if(m_buffer)
    {
        m_size = len;
        memcpy(m_buffer, str, len);
    }
    assert(m_buffer != NULL);
}

void BinaryBuffer::append(char* str, int len)
{
    // increase capacity if necessary
    capacity(m_size + len);
    // append new data to the buffer
    if(m_buffer)
    {
        memcpy(m_buffer + m_size, str, len);
        m_size += len;
    }
    assert(m_buffer != NULL);
}

void BinaryBuffer::capacity(int capacity)
{
    if(capacity > m_capacity)
    {
        // should resize internal buffer
        char *tmpbuf = new char[capacity];
        if(tmpbuf && m_buffer)
        {
            memcpy(tmpbuf, m_buffer, m_size);
            delete m_buffer;
            m_buffer = tmpbuf;
            m_capacity = capacity;
        }
    }
    assert(m_buffer != NULL);
}

void BinaryBuffer::size(int newsize)
{
    if(newsize > m_capacity)
    {
        capacity(newsize);
    }
    m_size = newsize;
}


