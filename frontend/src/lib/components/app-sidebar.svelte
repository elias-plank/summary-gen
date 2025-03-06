<script lang="ts" module>
    import AudioWaveform from "lucide-svelte/icons/audio-waveform";
    import BookOpen from "lucide-svelte/icons/book-open";
    import Bot from "lucide-svelte/icons/bot";
    import ChartPie from "lucide-svelte/icons/chart-pie";
    import Frame from "lucide-svelte/icons/frame";
    import GalleryVerticalEnd from "lucide-svelte/icons/gallery-vertical-end";
    import Map from "lucide-svelte/icons/map";
    import Settings2 from "lucide-svelte/icons/settings-2";
    import SquareTerminal from "lucide-svelte/icons/square-terminal";

    // This is sample data.
    const data = {
        user: {
            name: "shadcn",
            email: "m@example.com",
            avatar: "/avatars/shadcn.jpg",
        },
        navMain: [
            {
                title: "Execute",
                url: "#",
                icon: SquareTerminal,
                isActive: true,
                items: [
                    {
                        title: "History",
                        url: "#",
                    },
                    {
                        title: "Starred",
                        url: "#",
                    },
                    {
                        title: "Settings",
                        url: "#",
                    },
                ],
            },
            {
                title: "Models",
                url: "#",
                icon: Bot,
                items: [
                    {
                        title: "Genesis",
                        url: "#",
                    },
                    {
                        title: "Explorer",
                        url: "#",
                    },
                    {
                        title: "Quantum",
                        url: "#",
                    },
                ],
            },
            {
                title: "Settings",
                url: "#",
                icon: Settings2,
                items: [
                    {
                        title: "General",
                        url: "#",
                    },
                    {
                        title: "Team",
                        url: "#",
                    },
                    {
                        title: "Billing",
                        url: "#",
                    },
                    {
                        title: "Limits",
                        url: "#",
                    },
                ],
            },
        ],
        projects: [
            {
                name: "Design Engineering",
                url: "#",
                icon: Frame,
            },
            {
                name: "Sales & Marketing",
                url: "#",
                icon: ChartPie,
            },
            {
                name: "Travel",
                url: "#",
                icon: Map,
            },
        ],
    };
</script>

<script lang="ts">
    import NavMain from "$lib/components/nav-main.svelte";
    import NavJobs from "@/components/nav-jobs.svelte";
    import NavUser from "$lib/components/nav-user.svelte";
    import * as Sidebar from "$lib/components/ui/sidebar/index.js";
    import type { ComponentProps } from "svelte";

    let {
        ref = $bindable(null),
        collapsible = "icon",
        ...restProps
    }: ComponentProps<typeof Sidebar.Root> = $props();
</script>

<Sidebar.Root bind:ref {collapsible} {...restProps}>
    <Sidebar.Header>
        <Sidebar.Menu>
            <Sidebar.MenuItem>
                <Sidebar.MenuButton size="lg">
                    {#snippet child({ props })}
                        <a href="##" {...props}>
                            <div
                                class="bg-sidebar-primary text-sidebar-primary-foreground flex aspect-square size-8 items-center justify-center rounded-lg"
                            >
                                <!-- TODO(elias): icon -->
                                <GalleryVerticalEnd class="size-4" />
                            </div>
                            <div class="flex flex-col gap-0.5 leading-none">
                                <span class="font-semibold">SummaryGen</span>
                                <span class="">v1.0.0</span>
                            </div>
                        </a>
                    {/snippet}
                </Sidebar.MenuButton>
            </Sidebar.MenuItem>
        </Sidebar.Menu>
    </Sidebar.Header>
    <Sidebar.Content>
        <NavMain items={data.navMain} />
        <NavJobs projects={data.projects} />
    </Sidebar.Content>
    <Sidebar.Footer>
        <NavUser user={data.user} />
    </Sidebar.Footer>
    <Sidebar.Rail />
</Sidebar.Root>
