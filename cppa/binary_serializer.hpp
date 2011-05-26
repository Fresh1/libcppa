#ifndef BINARY_SERIALIZER_HPP
#define BINARY_SERIALIZER_HPP

#include <utility>
#include "cppa/serializer.hpp"

namespace cppa {

namespace detail { class binary_writer; }

class binary_serializer : public serializer
{

    friend class detail::binary_writer;

    char* m_begin;
    char* m_end;
    char* m_wr_pos;

    // make that it's safe to write num_bytes bytes to m_wr_pos
    void acquire(size_t num_bytes);

 public:

    binary_serializer();

    ~binary_serializer();

    void begin_object(const std::string& tname);

    void end_object();

    void begin_sequence(size_t list_size);

    void end_sequence();

    void write_value(const primitive_variant& value);

    void write_tuple(size_t size, const primitive_variant* values);

    /**
     * @brief Takes the internal buffer and returns it.
     *
     */
    std::pair<size_t, char*> take_buffer();

    /**
     * @brief Returns the number of written bytes.
     */
    size_t size() const;

    /**
     * @brief Returns a pointer to the internal buffer.
     */
    const char* data() const;

};

} // namespace cppa

#endif // BINARY_SERIALIZER_HPP