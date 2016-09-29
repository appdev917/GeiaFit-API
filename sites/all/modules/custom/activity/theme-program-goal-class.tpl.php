                    
                    <?php //dsm($program_goal); ?>
                    <?php //dsm($program_class); ?>
                     
                    <?php if(!empty($program_goal)): ?>
                        <h3>Program Goals</h3>
                        <?php 
                            foreach ($program_goal as $key => $value):
                                $node = node_view($value);
                                print render($node);
                            endforeach; 
                        ?>
                    <?php endif; ?>

                    
                    <?php if(!empty($program_class)): ?>
                        <hr>
                        <?php 
                            foreach ($program_class as $key => $value):
                                $node = node_view($value);
                                print render($node);
                            endforeach; 
                        ?>
                    <?php endif; ?>
                    <br>
                    
                    