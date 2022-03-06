
MEMORY
{
    FLASH (RX) : ORIGIN = 0x00000000, LENGTH = 0x00040000
    SRAM (WRX)  : ORIGIN = 0x20000000, LENGTH = 0x00008000
}



SECTIONS {

    PROVIDE (_intvecs_base_address = 0x0);
	
	PROVIDE (_sprints_base_address = 0x1000);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        KEEP (*(.intvecs))
    } > FLASH
	

    .text : {
        CREATE_OBJECT_SYMBOLS
        *(.text)
        *(.text.*)
    } > FLASH

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > FLASH

    .sprints (_sprints_base_address) : AT (_sprints_base_address) {
        KEEP (*(.sprints))
    } > FLASH
	
    .data : ALIGN (4) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (4);
        __data_end__ = .;
    } > SRAM AT> FLASH

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN (4);
        __bss_end__ = .;
    } > SRAM

    .stack : ALIGN(0x8) {
        _stack = .;
        __stack = .;
        KEEP(*(.stack))
    } > SRAM
}
