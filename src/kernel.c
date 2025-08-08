//
// Created by Prashant Kumar Jha on 08/08/25.
//
#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/util.h"
#include "../include/shell.h"
#include "../include/screen.h"  // Added for clearScreen() and printf()
#include "../include/system.h"  // Recommended for kernel main

// Main kernel entry point
void kmain(void)
{
    // Initialize core systems
    isr_install();
    idt_init();  // Make sure you initialize IDT as well

    // Initialize screen
    clearScreen();

    // Welcome message
    printf("Welcome to Kernelite! The OS that reminds you of how good computers\n");
    printf("were back then.. Anyway, just execute any command you want\n");
    printf("'help' is your friend :)\n\n");

    // Start shell
    launch_shell(0);

    // Halt if shell returns (shouldn't happen)
    for(;;) {
        asm("hlt");
    }
}