#ifndef PACKET_HPP_QYLSJSX5
#define PACKET_HPP_QYLSJSX5

#include <vanetza/common/byte_buffer.hpp>
#include <vanetza/net/osi_layer.hpp>
#include <cstddef>
#include <map>

namespace vanetza
{

class Packet
{
public:
    typedef std::map<OsiLayer, ByteBuffer> map_t;
    Packet();
    void swap(OsiLayer layer, ByteBuffer&);
    const ByteBuffer& operator[](OsiLayer layer) const;
    ByteBuffer& operator[](OsiLayer layer) { return mBuffers[layer]; }
    std::size_t size() const;
    void clear();

    map_t::iterator begin() { return mBuffers.begin(); }
    map_t::iterator end() { return mBuffers.end(); }
    map_t::const_iterator begin() const { return mBuffers.begin(); }
    map_t::const_iterator end() const { return mBuffers.end(); }

private:
    map_t mBuffers;
};

} // namespace vanetza

#endif /* PACKET_HPP_QYLSJSX5 */

