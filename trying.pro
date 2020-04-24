TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets

QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


INCLUDEPATH += ..\..\..\boost_1_72_0
INCLUDEPATH += ..\..\..\socket.io-client-cpp\lib\rapidjson
INCLUDEPATH += ..\..\..\socket.io-client-cpp\lib\websocketpp
INCLUDEPATH += ..\..\..\socket.io-client-cpp

SOURCES += \
    ../../../socket.io-client-cpp/lib/websocketpp/docs/simple_broadcast_server.cpp \
    ../../../socket.io-client-cpp/lib/websocketpp/docs/simple_count_server_thread.cpp \
    ../../../socket.io-client-cpp/src/internal/sio_client_impl.cpp \
    ../../../socket.io-client-cpp/src/internal/sio_packet.cpp \
    ../../../socket.io-client-cpp/src/sio_client.cpp \
    ../../../socket.io-client-cpp/src/sio_socket.cpp \
    data.cpp \
    login.cpp \
    main.cpp



HEADERS += \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/allocators.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/document.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/encodedstream.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/encodings.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/error/en.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/error/error.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/filereadstream.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/filestream.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/filewritestream.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/biginteger.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/diyfp.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/dtoa.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/ieee754.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/itoa.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/meta.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/pow10.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/stack.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/strfunc.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/internal/strtod.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/memorybuffer.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/memorystream.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/msinttypes/inttypes.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/msinttypes/stdint.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/prettywriter.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/rapidjson.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/reader.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/stringbuffer.h \
    ../../../socket.io-client-cpp/lib/rapidjson/include/rapidjson/writer.h \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/base64/base64.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/client.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/close.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/chrono.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/connection_hdl.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/cpp11.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/functional.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/md5.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/memory.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/network.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/platforms.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/random.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/regex.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/stdint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/system_error.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/thread.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/common/time.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/concurrency/basic.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/concurrency/none.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/asio.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/asio_client.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/asio_no_tls.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/asio_no_tls_client.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/boost_config.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/core.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/core_client.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/debug.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/debug_asio.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/debug_asio_no_tls.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/minimal_client.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/config/minimal_server.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/connection_base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/endpoint_base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/error.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/extensions/extension.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/extensions/permessage_deflate/disabled.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/extensions/permessage_deflate/enabled.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/frame.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/constants.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/impl/parser.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/impl/request.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/impl/response.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/parser.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/request.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/http/response.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/impl/connection_impl.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/impl/endpoint_impl.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/impl/utilities_impl.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/logger/basic.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/logger/levels.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/logger/stub.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/logger/syslog.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/message_buffer/alloc.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/message_buffer/message.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/message_buffer/pool.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/hybi00.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/hybi07.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/hybi08.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/hybi13.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/processors/processor.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/random/none.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/random/random_device.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/roles/client_endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/roles/server_endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/server.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/sha1/sha1.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/security/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/security/none.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/asio/security/tls.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/base/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/base/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/debug/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/debug/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/debug/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/iostream/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/iostream/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/iostream/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/stub/base.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/stub/connection.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/transport/stub/endpoint.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/uri.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/utf8_validator.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/utilities.hpp \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/version.hpp \
    ../../../socket.io-client-cpp/src/internal/sio_client_impl.h \
    ../../../socket.io-client-cpp/src/internal/sio_packet.h \
    ../../../socket.io-client-cpp/src/sio_client.h \
    ../../../socket.io-client-cpp/src/sio_message.h \
    ../../../socket.io-client-cpp/src/sio_socket.h \
    data.h \
    login.h


FORMS += \
    login.ui

DISTFILES += \
    ../../../socket.io-client-cpp/.gitignore \
    ../../../socket.io-client-cpp/.gitmodules \
    ../../../socket.io-client-cpp/.travis.yml \
    ../../../socket.io-client-cpp/API.md \
    ../../../socket.io-client-cpp/BOOST.md \
    ../../../socket.io-client-cpp/CMakeLists.txt \
    ../../../socket.io-client-cpp/INSTALL.md \
    ../../../socket.io-client-cpp/INSTALL_IOS.md \
    ../../../socket.io-client-cpp/LICENSE \
    ../../../socket.io-client-cpp/README.md \
    ../../../socket.io-client-cpp/lib/rapidjson/.gitignore \
    ../../../socket.io-client-cpp/lib/rapidjson/.gitmodules \
    ../../../socket.io-client-cpp/lib/rapidjson/.travis.yml \
    ../../../socket.io-client-cpp/lib/rapidjson/CMakeLists.txt \
    ../../../socket.io-client-cpp/lib/rapidjson/CMakeModules/FindGTestSrc.cmake \
    ../../../socket.io-client-cpp/lib/rapidjson/RapidJSON.pc.in \
    ../../../socket.io-client-cpp/lib/rapidjson/RapidJSONConfig.cmake.in \
    ../../../socket.io-client-cpp/lib/rapidjson/RapidJSONConfigVersion.cmake.in \
    ../../../socket.io-client-cpp/lib/rapidjson/appveyor.yml \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/glossary.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/menu.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/readme.txt \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/sample.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/webapp.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/data/widget.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf16be.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf16bebom.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf16le.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf16lebom.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf32be.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf32bebom.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf32le.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf32lebom.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf8.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/encodings/utf8bom.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail1.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail10.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail11.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail12.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail13.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail14.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail15.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail16.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail17.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail18.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail19.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail2.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail20.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail21.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail22.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail23.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail24.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail25.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail26.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail27.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail28.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail29.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail3.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail30.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail31.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail32.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail33.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail4.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail5.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail6.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail7.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail8.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/fail9.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/pass1.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/pass2.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/pass3.json \
    ../../../socket.io-client-cpp/lib/rapidjson/bin/jsonchecker/readme.txt \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/CMakeLists.txt \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/Doxyfile.in \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/insituparsing.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/insituparsing.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/iterative-parser-states-diagram.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/iterative-parser-states-diagram.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move1.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move1.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move2.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move2.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move3.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/move3.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/normalparsing.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/normalparsing.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/simpledom.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/simpledom.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/tutorial.dot \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/diagram/tutorial.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/dom.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/encoding.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/faq.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/features.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/internals.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/logo/rapidjson.png \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/logo/rapidjson.svg \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/misc/DoxygenLayout.xml \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/misc/doxygenextra.css \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/misc/footer.html \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/misc/header.html \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/performance.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/sax.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/stream.md \
    ../../../socket.io-client-cpp/lib/rapidjson/doc/tutorial.md \
    ../../../socket.io-client-cpp/lib/rapidjson/license.txt \
    ../../../socket.io-client-cpp/lib/rapidjson/readme.md \
    ../../../socket.io-client-cpp/lib/rapidjson/travis-doxygen.sh \
    ../../../socket.io-client-cpp/lib/websocketpp/.gitattributes \
    ../../../socket.io-client-cpp/lib/websocketpp/.gitignore \
    ../../../socket.io-client-cpp/lib/websocketpp/.travis.yml \
    ../../../socket.io-client-cpp/lib/websocketpp/CMakeLists.txt \
    ../../../socket.io-client-cpp/lib/websocketpp/COPYING \
    ../../../socket.io-client-cpp/lib/websocketpp/Doxyfile \
    ../../../socket.io-client-cpp/lib/websocketpp/SConstruct \
    ../../../socket.io-client-cpp/lib/websocketpp/changelog.md \
    ../../../socket.io-client-cpp/lib/websocketpp/cmake/CMakeHelpers.cmake \
    ../../../socket.io-client-cpp/lib/websocketpp/readme.md \
    ../../../socket.io-client-cpp/lib/websocketpp/roadmap.md \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp-config.cmake.in \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp-configVersion.cmake.in \
    ../../../socket.io-client-cpp/lib/websocketpp/websocketpp/CMakeLists.txt \
    ../../../socket.io-client-cpp/src/internal/.DS_Store \
    NodeImport.qml \
    chat.js
