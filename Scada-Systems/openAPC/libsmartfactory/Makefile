DBGFLAGS = -O2 -g0
ifeq ($(DEBUG),1)
DBGFLAGS = -O0 -g3 -DNOSPLASH
endif
ifeq ($(PROFILE),1)
DBGFLAGS = -O2 -g3
endif

CFLAGS = $(shell wx-config --cflags)
LFLAGS = -Wl,-whole-archive \
	$(shell wx-config --libs) \
	-Wl,-no-whole-archive

CCOMPILER=libtool --mode=compile g++ -Wall -fPIC -shared -fvisibility=hidden -shared -Wno-unused -Wno-unused-local-typedefs $(DBGFLAGS) \
	-DSF_EXT_EXPORTS -D_REENTRANT -DENV_LINUX -I.  -I.. -I ../liboapc -I../plugins $(CFLAGS) -Imqtt/MQTTSNPacket/src/

EXECUTABLE=libsmartfactory.la

LINK=libtool --mode=link g++ -shared -fvisibility=hidden -shared -export-symbols-regex 'sf_' -rpath /usr/lib

OBJECTS = libsmartfactoryInc.lo mqtt/MQTTPacket/src/MQTTConnectClient.lo mqtt/MQTTPacket/src/MQTTPacket.lo mqtt/MQTTPacket/src/MQTTSerializePublish.lo

default: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(LINK) $(SYSLDFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)
	cp -ax .libs/libsmartfactory.so* ../
	sudo cp -ax .libs/libsmartfactory.so* /usr/lib/ &
	sudo cp -ax .libs/libsmartfactory.so* /usr/lib64/ &

%.lo: %.cpp
	$(CCOMPILER) -c $< -o $@

%.lo: %.c
	$(CCOMPILER) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)



