public abstract class Akcija {
    private SlijedBrojeva slijedBrojeva;

    public void setSlijedBrojeva(SlijedBrojeva slijedBrojeva) {
        this.slijedBrojeva = slijedBrojeva;
    }

    public SlijedBrojeva getSlijedBrojeva() {
        return slijedBrojeva;
    }

    public void radi(){};
}
