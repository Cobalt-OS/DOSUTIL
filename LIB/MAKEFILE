CC = *wcc
CFLAGS = -oneatx -ohirbk -ol -ol+ -oi -ei -zp4 -0 -s -ri -ms /bt=dos

all: basenaml.obj dirnamel.obj getopt.obj

basenaml.obj: basenaml.c
        $(CC) $(CFLAGS) $? -fo=$@

dirnamel.obj: dirnamel.c
        $(CC) $(CFLAGS) $? -fo=$@

getopt.obj: getopt.c
        $(CC) $(CFLAGS) $? -fo=$@

clean-obj: .SYMBOLIC
        @if exist del *.obj
