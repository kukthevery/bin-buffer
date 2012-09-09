
/**
* @file           Cbuffer.h
* @title          Binary buffer class
* @author      Kukushkin Vladimir
*/

#ifndef _CBUFFER_H_
#define _CBUFFER_H_

/// Binary Buffer
// @short Class:  the binary buffer class
class BinaryBuffer
{
public:
    
    // Allocate a buffer of 'len' bytes long with capacity
    // to grow without reallocation to 'capacity' bytes.
    BinaryBuffer(int len = 0, int capacity = 1024);
    
    // Allocate a buffer 'len' bytes long and with capacity to grow without 
    // reallocation to 'capacity' bytes. Copy the data over.
    BinaryBuffer(char* buf, int len, int capacity = 1024, bool owner = true);
    
    // Destructor deletes allocated internal buffer if exists
    virtual ~BinaryBuffer(void);

    // Copy data into the buffer, growing the underlying
    // buffer if necessary. After this call b.size () == n.
    virtual void copy(char* str, int len);
    virtual void copy(BinaryBuffer& s)
    {
        copy(s.m_buffer, s.m_size);
    }
    // Append data to the buffer, growing the underlying
    // buffer if necessary. After this call b.size () == n.
    virtual void append(char* str, int len);
    virtual void append(BinaryBuffer& s)
    {
        append(s.m_buffer, s.m_size);
    }
    
    // Get pointer to the data buffer
    virtual char* data(void)
    {
        return m_buffer;
    }

    // Get size of the buffer
    virtual int size(void)
    {
        return m_size;
    }
    /// Set new size of the buffer, growing capacity if necessary
    virtual void size(int newSize);

    // Get capacity of the buffer
    virtual int capacity(void)
    {
        return m_capacity;
    }
    /// Set new capacity of the buffer,  growing capacity if necessary
    virtual void capacity(int newCapacity);

private:
    char *m_buffer;
    int m_capacity;
    int m_size;
    bool m_owner;

};

#endif /* _CBUFFER_H_ */
