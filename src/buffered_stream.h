#ifndef CIO_BUFFERED_STREAM_H
#define CIO_BUFFERED_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file
 * @brief This file contains the definitions all users of a cio_buffered_stream
 * need to know.
 *
 * A cio_buffered_stream is always greedy to fill its internal read
 * buffer. Therefore, it greatly reduces the amount of read calls into
 * the underlying operating system.
 *
 * Additonally, a cio_buffered_stream gives you the concept of reading
 * an exact number of bytes or reading until a delimiter string is
 * encountered. Both concepts are useful when parsing protocols.
 *
 * A @p writev call into a buffered_stream only writes into the internal
 * write buffer. The write buffer is flushed only if the internal write
 * buffer is called or @p flush is called explicitly
 */

/**
 * Interface description for implementing buffered I/O.
 */
struct cio_buffered_stream {
	/**
	 * @brief The context pointer which is passed to the functions
	 * specified below..
	 */
	void *context;
	void (*read_exactly)(void *context, size_t num, cio_stream_handler handler, void *handler_context);

	/**
	 * @brief Read upto @p count bytes into the buffer @p buf starting
	 * with offset @p offset.
	 *
	 * @param context A pointer to the cio_io_stream::context of the
	 * implementation implementing this interface.
	 * @param buf The buffer to be filled.
	 * @param offset The start offset in @p buf at which the data is
	 * written.
	 * @param count The maximum number of bytes to read.
	 * @param handler The callback function to be called when the read
	 * request is (partly) fulfilled.
	 * @param handler_context A pointer to a context which might be
	 * useful inside @p handler
	 */
	void (*read)(void *context, size_t num, cio_stream_handler handler, void *handler_context);
	void (*read_until)(void *context, const char *delim, cio_stream_handler handler, void *handler_context);

	/**
	 * @brief Writes @p count buffers to the buffered stream.
	 *
	 * Please note that the data written is not immediatly forwarded to
	 * the underlying cio_io_stream. Call cio_buffered_stream::flush to do so.
	 *
	 * @param context A pointer to the cio_io_stream::context of the
	 * implementation implementing this interface.
	 * @param io_vec An array of cio_io_vector buffers.
	 * @param count Number of cio_io_vector buffers in @p io_vec.
	 * @param handler The callback function to be called when the write
	 * request is fulfilled.
	 * @param handler_context A pointer to a context which might be
	 * useful inside @p handler
	 */
	void (*writev)(void *context, struct cio_io_vector *io_vec, unsigned int count, cio_stream_handler handler, void *handler_context);

	/**
	 * Drains the data in the write buffer out to the underlying
	 * cio_io_stream.
	 */
	void (*flush)(void *context);

	/**
	 * @brief Closes the stream.
	 *
	 * Implementations implementing this interface are strongly
	 * encouraged to flush any write buffers and to free other resources
	 * associated with this stream.
	 */
	void (*close)(void *context);
};

#ifdef __cplusplus
}
#endif

#endif
