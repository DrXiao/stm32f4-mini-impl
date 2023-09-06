ENTRY(reset_handler)

MEMORY
{
	FLASH (rx) 	: ORIGIN = 0x08000000, LENGTH = 1024K,
	RAM (rwx) 	: ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
	.text :
	{
		KEEP(*(.isr_vector))
		*(.text)
		*(.text.*)
		*(.rodata)
		_sromdev = .;
		_eromdev = .;
		_sidata = .;
	} >FLASH

	.data :
	{
		_sdata = .;
		*(.data)
		*(.data*)
		_edata = .;
	} >RAM AT> FLASH

	.bss :
	{
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		_ebss = .;
		__bss_end__ = _ebss;
	} >RAM

	_estack = ORIGIN(RAM) + LENGTH(RAM);
}
