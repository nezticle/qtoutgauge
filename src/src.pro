TEMPLATE = subdirs
SUBDIRS += outgauge

qtHaveModule(quick) {
    SUBDIRS += imports
}

imports.depends = outgauge