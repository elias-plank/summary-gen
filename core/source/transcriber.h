//
//  MIT License
//
//  Copyright (c) 2025 Elias Engelbert Plank
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#ifndef TRANSCRIBER_H
#define TRANSCRIBER_H

#include "rwlock.h"
#include "types.h"

#include <transcriber.grpc.pb.h>
#include <whisper.h>

struct TranscriberService final : Transcriber::Service {

    /**
     * Instantiates a new transcriber service
     * @param model_path The path to the whisper model
     */
    explicit TranscriberService(fs::path const &model_path);

    /**
     * Transcribes a given video
     * @param context The server context
     * @param stream Used for accessing the data
     * @return A grpc status
     */
    grpc::Status transcribe(grpc::ServerContext *context, grpc::ServerReaderWriter<Transcript, Chunk> *stream) override;

    /**
     * Endpoint for checking whether the transcriber service is running
     * @param context The server context
     * @param request The heartbeat request, which is empty
     * @param response The response, which is empty
     * @return A grpc status
     */
    grpc::Status heartbeat(grpc::ServerContext *context,
                           const google::protobuf::Empty *request,
                           google::protobuf::Empty *response) override;

private:
    using WhisperContext = std::unique_ptr<whisper_context, decltype((whisper_free))>;
    std::unique_ptr<ReadWriteLock<WhisperContext>> m_context;
};

#endif// TRANSCRIBER_H
