<script lang="ts">
    import CounterClockwiseClock from "svelte-radix/CounterClockwiseClock.svelte";
    import { Button } from "$lib/components/ui/button";
    import { Label } from "$lib/components/ui/label";
    import { Textarea } from "$lib/components/ui/textarea";
</script>

<div class="hidden h-full flex-col md:flex">
    <div class="container h-full py-6">
        <div class="flex flex-col space-y-4">
            <div class="grid h-full gap-6 lg:grid-cols-2">
                <div class="flex flex-col space-y-4">
                    <div class="flex flex-1 flex-col space-y-2">
                        <Label for="input">Input</Label>
                        <Textarea
                            id="input"
                            placeholder="We is going to the market."
                            class="flex-1 lg:min-h-[580px]"
                        />
                    </div>
                    <div class="flex flex-col space-y-2">
                        <Label for="instructions">Instructions</Label>
                        <Textarea
                            id="instructions"
                            placeholder="Fix the grammar."
                        />
                    </div>
                </div>
                <div
                    class="bg-muted mt-[21px] min-h-[400px] rounded-md border lg:min-h-[700px]"
                ></div>
            </div>
            <div class="flex items-center space-x-2">
                <Button>Submit</Button>
                <Button variant="secondary">
                    <span class="sr-only">Show history</span>
                    <CounterClockwiseClock class="h-4 w-4" />
                </Button>
            </div>
        </div>
    </div>
</div>
